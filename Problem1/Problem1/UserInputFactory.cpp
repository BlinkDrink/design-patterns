#include <iostream>
#include <fstream>

#include "UserInputFactory.h"
#include "DoubleGenerator.h"
#include "RandomFigureFactory.h"
#include "StreamFigureFactory.h"

using std::make_unique;
using std::cout;
using std::cin;
using std::ifstream;
using std::invalid_argument;

namespace Problem1
{
	namespace Factories
	{

		unique_ptr<FigureFactory> UserInputFactory::create_figure_factory(const string& input_type) const // File/STDIN/Random
		{
			if (input_type == "Random")
			{
				srand(time(nullptr));
				return make_unique<RandomFigureFactory>(new DoubleGenerator);
			}
			else if (input_type == "STDIN")
			{
				return make_unique<StreamFigureFactory>(cin);
			}
			else if (input_type == "File") {
				string filename;
				cout << "Enter file name: ";
				cin >> filename;
				ifstream file(filename); // file.close()
				return make_unique<StreamFigureFactory>(std::move(file)); // TODO: File gets closed when exiting scope
			}

			throw invalid_argument("Invalid input type");
		}
	}
}
