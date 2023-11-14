#include <stdexcept>

#include "Triangle.h"
#include "Utils.h"

using std::invalid_argument;
using std::to_string;
using std::swap;

namespace Problem1
{
	namespace Figures
	{
		Triangle::Triangle(double a, double b, double c)
		{
			if (a < 0 || b < 0 || c < 0)
				throw std::invalid_argument("Sides of triangle cannot be negative numbers");

			if (a + b < c || b + c < a || a + c < b)
				throw invalid_argument("Invalid triangle");

			this->a = a;
			this->b = b;
			this->c = c;

			if (this->a > this->b)
				swap(this->a, this->b);
			if (this->a > this->c)
				swap(this->a, this->c);
			if (this->b > this->c)
				swap(this->b, this->c);
		}

		double Triangle::perimeter() const
		{
			return a + b + c;
		}

		string Triangle::toString() const
		{
			string aStr = to_string(a);
			string bStr = to_string(b);
			string cStr = to_string(c);

			remove_trailing_zeroes(aStr);
			remove_trailing_zeroes(bStr);
			remove_trailing_zeroes(cStr);

			return "triangle " + aStr + " " + bStr + " " + cStr;
		}

		bool Triangle::operator==(const Figure& other) const
		{
			const Triangle* cast = dynamic_cast<const Triangle*>(&other);
			if (!cast)
				return false;

			return abs(a - cast->a) < DBL_EPSILON && abs(b - cast->b) < DBL_EPSILON && abs(c - cast->c) < DBL_EPSILON;
		}

		unique_ptr<Figure> Triangle::clone() const
		{
			return std::make_unique<Triangle>(*this);
		}

	}
}
