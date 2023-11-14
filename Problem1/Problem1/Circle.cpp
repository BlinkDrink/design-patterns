#include <cmath>
#include "Circle.h"
#include <corecrt_math_defines.h>
#include "Utils.h"

namespace Problem1
{
	namespace Figures
	{

		Circle::Circle(double radius)
		{
			if (radius < 0)
				throw std::invalid_argument("Radius cannot be a negative number");
			this->radius = radius;
		}

		double Circle::perimeter() const
		{
			return 2 * M_PI * radius;
		}

		string Circle::toString() const
		{
			string r = std::to_string(radius);
			remove_trailing_zeroes(r);
			return "circle " + r;
		}

		bool Circle::operator==(const Circle& other) const
		{
			return abs(this->radius - other.radius) < DBL_EPSILON;
		}

		unique_ptr<Figure> Circle::clone() const
		{
			return std::make_unique<Circle>(*this);
		}
	}
}
