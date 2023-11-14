#include "StreamFigureFactory.h"
#include <stdexcept>
#include<sstream>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using Problem1::Figures::Circle;
using Problem1::Figures::Triangle;
using Problem1::Figures::Rectangle;

using std::invalid_argument;
using std::stringstream;
using std::make_unique;

namespace Problem1
{
	namespace Factories
	{
		StreamFigureFactory::StreamFigureFactory(istream& s) : m_stream(s) {}

		StreamFigureFactory::StreamFigureFactory(ifstream&& s) : m_file(std::move(s)), m_stream(m_file) {}

		unique_ptr<Figure> StreamFigureFactory::create_figure() const
		{
			string type;
			if (!(m_stream >> type))
				throw invalid_argument("Invalid figure name in file");

			if (type == "triangle") {
				double a, b, c;
				if (!(m_stream >> a >> b >> c))
					throw invalid_argument("Invalid triangle format in file");

				return make_unique<Triangle>(a, b, c);
			}
			else if (type == "rectangle")
			{
				double a, b;
				if (!(m_stream >> a >> b))
					throw invalid_argument("Invalid rectangle format in file");

				return make_unique<Rectangle>(a, b);
			}
			else if (type == "circle")
			{
				double radius;
				if (!(m_stream >> radius))
					throw invalid_argument("Invalid circle format in file");

				return make_unique<Circle>(radius);
			}

			throw invalid_argument("Invalid figure type");
		}
	}
}
