#include <filesystem>
#include <iostream>
#include <memory>
#include <memory>
#include <ostream>

#include "Engine.h"
#include "BuilderBase.h"
#include "FollowLinksBuilder.h"
#include "MD5ChecksumCalculation.h"
#include "NoFollowLinksBuilder.h"
#include "PauseScanner.h"
#include "ReportWriter.h"
#include "ChecksumCalculationFactory.h"
#include "CommandType.h"
#include "ProgressReporter.h"

namespace fs = std::filesystem;

namespace Checksums
{
	namespace Engines
	{
		using std::cin;
		using std::cout;
		using std::endl;
		using std::string;
		using std::ofstream;
		using std::unique_ptr;
		using std::make_shared;
		using std::make_unique;
		using Visitors::HashStreamWriter;
		using Factories::ChecksumCalculationFactory;


		void Engine::menu() const
		{
			cout << "1. Print report for all files to be scanned\n";
			cout << "2. Scan all files and calculate their checksums\n";
			cout << "3. Pause a running scan\n";
			cout << "4. Resume a running scan\n";
			cout << "5. Exit\n";
		}

		unique_ptr<BuilderBase> Engine::createBuilder() const
		{
			unique_ptr<BuilderBase> builder;
			string links;
			cout << "Do you wish to follow symbolic links/shortcuts(y/n)?";
			cin >> links;
			if (links == "y")
			{
				builder = std::make_unique<Builders::FollowLinksBuilder>();
			}
			else
			{
				builder = std::make_unique<Builders::NoFollowLinksBuilder>();
			}

			return std::move(builder);
		}

		shared_ptr<ObserverBase> Engine::initializeHashStreamWriter() const
		{
			string checksumPath, alg;
			unique_ptr<ChecksumCalculations::ChecksumCalculationBase> hashAlg;
			while (true)
			{
				cout << "Enter path to file in which checksums will be written in format <hash> <filePath>:";
				cin >> checksumPath;
				ofstream output(checksumPath);
				if (!output.is_open())
				{
					cout << "Couldn't open file for reading";
				}
				else
				{
					cout << "Enter algorithm for checksums (md5/sha256):";
					ChecksumCalculationFactory calcFactory(cin);
					return make_shared<HashStreamWriter>(std::move(output), calcFactory.create_calculator());
				}
			}
		}

		string Engine::pathToFileInput() const
		{
			string path, finalPath;
			while (true)
			{
				cout << "Enter path to file/directory:";
				cin >> path;
				const fs::path currentPath = fs::current_path();
				const fs::path pathToPrint = currentPath / path;

				if (fs::exists(path))
				{
					finalPath = path;
					break;
				}

				if (fs::exists(pathToPrint))
				{
					finalPath = pathToPrint.string();
					break;
				}

				cout << "Invalid path to file\n";
			}

			return finalPath;
		}

		Engine::Engine() : m_pauseScanner(nullptr), m_visitor(nullptr), m_tree(nullptr)
		{
		}

		void Engine::initializePauseScanner(unique_ptr<TreeElements::FileTreeElement> tree)
		{
			m_writer = initializeHashStreamWriter();
			m_tree = std::move(tree);
			m_progressReporter = make_unique<ProgressReporter>(m_tree->getSize());
			VisitorBase* cast = dynamic_cast<VisitorBase*>(m_writer.get());
			shared_ptr<VisitorBase> castVisitor = shared_ptr<VisitorBase>(cast);
			m_pauseScanner = make_unique<Scanners::PauseScanner>(castVisitor, m_tree);
			m_pauseScanner->addObserver(m_writer);
			m_pauseScanner->addObserver(m_progressReporter);
		}

		Engine& Engine::getInstance()
		{
			static Engine instance;
			return instance;
		}

		void Engine::exe()
		{
			menu();
			string pathToFile = pathToFileInput();
			unique_ptr<BuilderBase> builder = createBuilder();
			builder->build(pathToFile);
			unique_ptr<TreeElements::FileTreeElement> tree = builder->getResult();

			std::thread inputThread([&]() {
				while (true)
				{
					size_t cmd;
					cout << "Enter command:";
					cin >> cmd;

					switch (static_cast<CommandType::CommandType>(cmd))
					{
					case CommandType::CommandType::REPORT:
					{
						Visitors::ReportWriter rw(cout);
						tree->accept(rw);
						break;
					}
					case CommandType::CommandType::SCAN:
					{
						initializePauseScanner(std::move(tree));
						m_pauseScanner->start();
						while (true)
						{
							cout << "Enter command while scanning:";
							cin >> cmd;
							switch (static_cast<CommandType::CommandType>(cmd))
							{
							case CommandType::CommandType::REPORT:
							{
								cout << "Scanning.. Please wait";
								break;
							}
							case CommandType::CommandType::SCAN:
								cout << "Already scanning\n";
								break;
							case CommandType::CommandType::PAUSE:
								try
								{
									m_pauseScanner->pause();
								}
								catch (std::exception& ex)
								{
									cout << ex.what() << endl;
								}
								break;
							case CommandType::CommandType::RESUME:
								try
								{
									m_pauseScanner->resume();
								}
								catch (std::exception& ex)
								{
									cout << ex.what() << endl;
								}
								break;
							case CommandType::CommandType::EXIT:
								return;
							}
						}
					}
					case CommandType::CommandType::PAUSE:
					{
						cout << "You must begin a scan in order to pause\n";
						break;
					}
					case CommandType::CommandType::RESUME:
					{
						cout << "You must begin a scan in order to resume";
						break;
					}
					case CommandType::CommandType::EXIT:
						return;
					}
				}
				});

			inputThread.join();
		}
	}
}

