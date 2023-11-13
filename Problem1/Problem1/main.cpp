#include<iostream>
#include <vector>
#include <exception>
#include <fstream>
#include "UserInputFactory.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::unique_ptr;
using std::ofstream;
using std::exception;

void printFigures(const vector<unique_ptr<Figure>>& figures)
{
	int counter = 0;
	for (const unique_ptr<Figure>& figure : figures) {
		cout << counter++ << " " << figure->toString() << std::endl;
	}
}

void menu()
{
	cout << "1. List figures to STDOUT" << endl;
	cout << "2. Delete a figure from the list" << endl;
	cout << "3. Duplicate a figure in the list" << endl;
	cout << "4. Store the resulting list back to file" << endl;
	cout << "5. Exit" << endl;
	cout << endl;
}

int main(int argc, const char* argv[])
{
	cout << "Choose input method (Random/STDIN/File): ";
	string input_type;
	cin >> input_type;

	const UserInputFactory inputFactory;
	const unique_ptr<FigureFactory> figureFactory = inputFactory.create_figure_factory(input_type);

	int numFigures;
	cout << "Enter the number of figures: ";
	cin >> numFigures;

	vector<unique_ptr<Figure>> figures;

	for (int i = 0; i < numFigures; ++i) {
		// Create a figure using the chosen factory
		figures.push_back(figureFactory->create_figure());
	}

	menu();


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
			int id;
			cout << "Enter the index of the figure you wish to delete:";
			cin >> id;

			if (id >= figures.size())
				cout << "Index out of bounds";

			figures.erase(figures.begin() + id);
			break;
		}
		case 3:
		{
			int id;
			cout << "Enter the index of the figure you wish to duplicate:";
			cin >> id;

			if (id >= figures.size())
				cout << "Index out of bounds";

			figures.push_back(figures[id]->clone());
			break;
		}
		case 4:
		{
			string filename;
			cout << "Enter file name:";
			cin >> filename;
			ofstream file(filename);
			if (!file.is_open())
				throw exception("Failed opening file for writing");

			for (const unique_ptr<Figure>& fig : figures)
			{
				file << fig->toString() << endl;
			}
			break;
		}
		case 5:
			return 0;
		default:
			continue;
		}
	}

	return 0;
}
