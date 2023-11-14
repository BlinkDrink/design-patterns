#include <cmath>
#include "Circle.h"
#include <corecrt_math_defines.h>
#include "Utils.h"

namespace Problem1
{
	namespace Figures
	{
		using std::make_unique;

		Circle::Circle(double radius)
		{
			if (radius < 0)
				throw std::invalid_argument("Radius cannot be a negative number");
			this->radius = radius;

			string r = std::to_string(radius);
			remove_trailing_zeroes(r);

			m_perimeter = 2 * M_PI * this->radius;
			m_string_format = "circle " + r;
		}

		double Circle::perimeter() const
		{
			return m_perimeter;
		}

		string Circle::toString() const
		{
			return m_string_format;
		}

		bool Circle::operator==(const Figure& other) const
		{
			const Circle* cast = dynamic_cast<const Circle*>(&other);
			if (!cast)
				return false;

			return abs(this->radius - cast->radius) < DBL_EPSILON;
		}

		unique_ptr<Figure> Circle::clone() const
		{
			return make_unique<Circle>(*this);
		}
	}
}
