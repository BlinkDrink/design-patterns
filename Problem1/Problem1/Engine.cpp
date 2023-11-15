#include "Engine.h"
#include <iostream>
#include <fstream>

#include "CommandType.h"
#include "UserInputFactory.h"

namespace Problem1
{
	namespace Engine
	{
		using std::cout;
		using std::cin;
		using std::endl;
		using std::ofstream;
		using std::exception;
		using std::invalid_argument;
		using Factories::UserInputFactory;
		using Factories::FigureFactory;
		using std::ostream;

		void Engine::menu() const
		{
			cout << "1. List figures to STDOUT" << endl;
			cout << "2. Delete a figure from the list" << endl;
			cout << "3. Duplicate a figure in the list" << endl;
			cout << "4. Store the resulting list back to file" << endl;
			cout << "5. Exit" << endl;
			cout << endl;
		}

		void Engine::outputFiguresTo(const vector<unique_ptr<Figure>>& figures, ostream& target) const
		{
			for (const unique_ptr<Figure>& fig : figures)
			{
				target << fig->toString() << endl;
			}
		}

		void Engine::duplicateAndAddFigure(vector<unique_ptr<Figure>>& figures) const
		{
			size_t id;
			cout << "Enter the index of the figure you wish to duplicate:";
			cin >> id;

			if (id >= figures.size())
				throw invalid_argument("Index out of bounds");

			figures.push_back(figures[id]->clone());
		}

		void Engine::removeFigure(vector<unique_ptr<Figure>>& figures) const
		{
			size_t id;
			cout << "Enter the index of the figure you wish to delete:";
			cin >> id;

			if (id >= figures.size())
				throw invalid_argument("Index out of bounds");

			figures.erase(figures.begin() + id);
		}

		Engine& Engine::getInstance()
		{
			static Engine instance;
			return instance;
		}

		void Engine::exe()
		{
			cout << "Choose input method (Random/STDIN/File): ";
			string input_type;
			cin >> input_type;

			unique_ptr<FigureFactory> figureFactory;
			try
			{
				figureFactory = UserInputFactory::getInstance().create_figure_factory(input_type);
			}
			catch (const exception& ex)
			{
				cout << "Creation of figure factory with input " << input_type << " has failed. " << ex.what() << endl;
				return;
			}

			int numFigures;
			cout << "Enter the number of figures: ";
			cin >> numFigures;

			vector<unique_ptr<Figure>> figures;

			try
			{
				figures.reserve(numFigures);
			}
			catch (const exception& ex)
			{
				cout << "Reserving memory for " << numFigures << " has failed. " << ex.what() << endl;
			}

			// Figure input
			for (int i = 0; i < numFigures; ++i)
			{
				try
				{
					figures.push_back(figureFactory->create_figure());
				}
				catch (const exception& ex)
				{
					cout << "Creation of figure number " << i << " has failed. " << ex.what() << endl;
				}
			}

			if (figures.empty())
			{
				cout << "After the input method the program couldn't create any figures. Exiting..." << endl;
				return;
			}

			menu();

			while (true)
			{
				size_t cmdId;
				cout << "Enter command(1/2/3/4/5):";
				cin >> cmdId;

				CommandType cmd = static_cast<CommandType>(cmdId);

				switch (cmd)
				{
				case CommandType::ListFigures:
				{
					outputFiguresTo(figures, cout);
					break;
				}
				case CommandType::RemoveFigure:
				{
					try
					{
						removeFigure(figures);
					}
					catch (const exception& ex)
					{
						cout << "Removing figure has failed. " << ex.what() << endl;
					}
					break;
				}
				case CommandType::DuplicateFigure:
				{
					try
					{
						duplicateAndAddFigure(figures);
					}
					catch (const exception& ex)
					{
						cout << "Duplicating figure has failed. " << ex.what() << endl;
					}
					break;
				}
				case CommandType::SaveFigures:
				{
					string filename;
					cout << "Enter file name:";
					cin >> filename;

					try
					{
						ofstream file(filename);

						if (!file.is_open())
						{
							cout << "Failed opening file " << filename << " for writing";
							break;
						}

						outputFiguresTo(figures, file);
					}
					catch (const exception& ex)
					{
						cout << "Saving figures to file " << filename << " has failed. " << ex.what() << endl;
					}
					break;
				}
				case CommandType::Exit:
					return;
				}
			}
		}
	}
}
