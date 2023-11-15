#include <iostream>
#include <fstream>

#include "UserInputFactory.h"
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
				double lower, upper;
				cout << "Enter lower bound:";
				cin >> lower;
				cout << "Enter upper bound:";
				cin >> upper;

				return make_unique<RandomFigureFactory>(lower, upper, time(nullptr));
			}
			else if (input_type == "STDIN")
			{
				return make_unique<StreamFigureFactory>(cin);
			}
			else if (input_type == "File") {
				string filename;
				cout << "Enter file name: ";
				cin >> filename;

				ifstream file(filename);
				if (!file.is_open())
					throw invalid_argument("File couldn't be opened for reading");

				return make_unique<StreamFigureFactory>(std::move(file));
			}

			throw invalid_argument("Invalid input type");
		}

		UserInputFactory& UserInputFactory::getInstance()
		{
			static UserInputFactory instance;
			return instance;
		}
	}
}
