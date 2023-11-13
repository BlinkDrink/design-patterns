#include<iostream>
#include <vector>
#include "UserInputFactory.h"

using std::cout;
using std::cin;
using std::vector;
using std::unique_ptr;

void printFigures(vector<unique_ptr<Figure>>& figures)
{
	for (const unique_ptr<Figure>& figure : figures) {
		cout << figure->toString() << std::endl;
	}
}

int main(int argc, const char* argv[])
{
	cout << "Choose input method (Random/STDIN/File): ";
	string input_type;
	cin >> input_type;

	UserInputFactory inputFactory;
	unique_ptr<FigureFactory> figureFactory = inputFactory.create_figure_factory(input_type);

	int numFigures;
	cout << "Enter the number of figures: ";
	cin >> numFigures;

	vector<unique_ptr<Figure>> figures;

	for (int i = 0; i < numFigures; ++i) {
		// Create a figure using the chosen factory
		figures.push_back(figureFactory->create_figure());
	}

	for (const auto& figure : figures) {
		cout << figure->toString() << " Perimeter: " << figure->perimeter() << std::endl;
	}

	return 0;
}
