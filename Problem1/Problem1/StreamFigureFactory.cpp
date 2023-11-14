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
		StreamFigureFactory::StreamFigureFactory(istream& s) : m_stream(s)
		{
		}

		StreamFigureFactory::StreamFigureFactory(ifstream&& s) : m_file(std::move(s)), m_stream(m_file)
		{
		}

		unique_ptr<Figure> StreamFigureFactory::create_figure() const
		{
			string type;
			m_stream >> type;

			// TODO: Reading input from m_stream may throw (i.e. "rectangle 3.5" this expects another value)
			if (type == "triangle") {
				double a, b, c;
				m_stream >> a >> b >> c;
				return make_unique<Triangle>(a, b, c);
			}
			else if (type == "rectangle")
			{
				double a, b;
				m_stream >> a >> b;
				return make_unique<Rectangle>(a, b);
			}
			else if (type == "circle")
			{
				double radius;
				m_stream >> radius;
				return make_unique<Circle>(radius);
			}

			throw invalid_argument("Invalid figure type");
		}
	}
}
