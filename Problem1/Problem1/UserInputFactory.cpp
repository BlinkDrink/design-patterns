#include <iostream>
#include<fstream>

#include "UserInputFactory.h"
#include "RandomFigureFactory.h"
#include "StreamFigureFactory.h"

using std::make_unique;
using std::cout;
using std::cin;
using std::ifstream;
using std::invalid_argument;

unique_ptr<FigureFactory> UserInputFactory::create_figure_factory(const string& input_type) const
{
	if (input_type == "Random") {
		srand(time(nullptr));
		return make_unique<RandomFigureFactory>();
	}
	else if (input_type == "STDIN") {
		return make_unique<StreamFigureFactory>(cin);
	}
	else if (input_type == "File") {
		string filename;
		cout << "Enter file name: ";
		cin >> filename;
		ifstream file(filename);
		return make_unique<StreamFigureFactory>(file); // TODO: File gets closed when exiting scope
	}

	throw invalid_argument("Invalid input type");
}
