#include "Engine.h"
#include <iostream>
#include <fstream>

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
		using Factories::UserInputFactory;
		using Factories::FigureFactory;

		void Engine::menu() const
		{
			cout << "1. List figures to STDOUT" << endl;
			cout << "2. Delete a figure from the list" << endl;
			cout << "3. Duplicate a figure in the list" << endl;
			cout << "4. Store the resulting list back to file" << endl;
			cout << "5. Exit" << endl;
			cout << endl;
		}

		void Engine::saveFiguresToFile(const string& filename, const std::vector<unique_ptr<Figure>>& figures) const
		{
			ofstream file(filename);

			if (!file.is_open())
				throw exception("Failed opening file for writing");

			for (const unique_ptr<Figure>& fig : figures)
			{
				file << fig->toString() << endl;
			}

			file.close();
		}

		void Engine::printFigures(const vector<unique_ptr<Figure>>& figures) const
		{
			int counter = 0;
			for (const unique_ptr<Figure>& figure : figures) {
				std::cout << counter++ << " " << figure->toString() << std::endl;
			}
		}

		void Engine::duplicateAndAddFigure(vector<unique_ptr<Figure>>& figures) const
		{
			size_t id;
			cout << "Enter the index of the figure you wish to duplicate:";
			cin >> id;

			if (id >= figures.size())
				cout << "Index out of bounds";

			figures.push_back(figures[id]->clone());
		}

		void Engine::removeFigure(vector<unique_ptr<Figure>>& figures) const
		{
			size_t id;
			cout << "Enter the index of the figure you wish to delete:";
			cin >> id;

			if (id >= figures.size())
				cout << "Index out of bounds";

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

			const unique_ptr<FigureFactory> figureFactory = UserInputFactory::getInstance().create_figure_factory(input_type);

			int numFigures;
			cout << "Enter the number of figures: ";
			cin >> numFigures;

			vector<unique_ptr<Figure>> figures;
			figures.reserve(numFigures);

			for (int i = 0; i < numFigures; ++i) {
				figures.push_back(figureFactory->create_figure());
			}

			menu();

			// TODO: Add enum type for commands
			while (true)
			{
				int cmd;
				cout << "Enter command (1/2/3/4/5):";
				cin >> cmd;

				switch (cmd)
				{
				case 1:
				{
					printFigures(figures);
					break;
				}
				case 2:
				{
					removeFigure(figures);
					break;
				}
				case 3:
				{
					duplicateAndAddFigure(figures);
					break;
				}
				case 4:
				{
					string filename;
					cout << "Enter file name:";
					cin >> filename;
					saveFiguresToFile(filename, figures);
					break;
				}
				default:
					return;
				}
			}
		}
	}
}
