#include "Rectangle.h"
#include "Utils.h"

using std::to_string;
using std::swap;
using std::make_unique;

namespace Problem1
{
	namespace Figures
	{
		Rectangle::Rectangle(double a, double b)
		{
			if (a < 0 || b < 0)
				throw std::invalid_argument("Sides of rectangle cannot be negative numbers");

			this->a = a;
			this->b = b;
			if (b < a)
				swap(this->a, this->b);
		}

		double Rectangle::perimeter() const
		{
			return 2 * (a + b);
		}

		string Rectangle::toString() const
		{
			string aStr = to_string(a);
			string bStr = to_string(b);

			remove_trailing_zeroes(aStr);
			remove_trailing_zeroes(bStr);

			return "rectangle " + aStr + " " + bStr;
		}

		bool Rectangle::operator==(const Rectangle& other) const
		{
			return abs(a - other.a) < DBL_EPSILON && abs(b - other.b) < DBL_EPSILON;
		}

		unique_ptr<Figure> Rectangle::clone() const
		{
			return make_unique<Rectangle>(*this);
		}
	}
}

