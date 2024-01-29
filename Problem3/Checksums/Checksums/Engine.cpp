#include "Engine.h"

#include <filesystem>
#include <iostream>
#include <memory>
#include <ostream>

#include "BuilderBase.h"
#include "FollowLinksBuilder.h"
#include "MD5ChecksumCalculation.h"
#include "NoFollowLinksBuilder.h"
#include "PauseScanner.h"
#include "ReportWriter.h"
#include "ChecksumCalculationFactory.h"

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

		std::shared_ptr<Observers::ObserverBase> Engine::initializeHashStreamWriter() const
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
					return std::make_shared<HashStreamWriter>(output, calcFactory.create_calculator());
				}
			}
		}

		Engine& Engine::getInstance()
		{
			static Engine instance;
			return instance;
		}

		void Engine::exe()
		{
			Scanners::PauseScanner ps;
			string path, finalPath;
			size_t cmd;

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

			unique_ptr<BuilderBase> builder = createBuilder();

			builder->build(finalPath);
			unique_ptr<TreeElements::FileTreeElement> tree = builder->getResult();

			while (true)
			{
				menu();
				cout << "Enter command:";
				cin >> cmd;

				if (cmd == 1)
				{
					Visitors::ReportWriter rw(cout);
					tree->accept(rw);
				}
				else if (cmd == 2)
				{
					std::shared_ptr<Observers::ObserverBase> writer = initializeHashStreamWriter();
					ps.addObserver(writer);
					ps.start();
				}
				else if (cmd == 3)
				{
					try
					{
						ps.pause();
					}
					catch (std::exception& e)
					{
						cout << e.what();
					}
				}
				else if (cmd == 4)
				{
					try
					{
						ps.resume();
					}
					catch (std::exception e)
					{
						cout << e.what();
					}
				}
				else if (cmd == 5)
				{
					return;
				}
			}
		}
	}
}

