#include "Rectangle.h"
#include "Utils.h"

using std::to_string;
using std::swap;
using std::make_unique;

namespace Problem1
{
	namespace Figures
	{
		using Utils::remove_trailing_zeroes;

		Rectangle::Rectangle(double a, double b)
		{
			if (a <= 0 || b <= 0)
				throw std::invalid_argument("Sides of rectangle cannot be non-positive numbers");

			this->a = a;
			this->b = b;
			if (b < a)
				swap(this->a, this->b);

			string aStr = to_string(this->a);
			string bStr = to_string(this->b);

			remove_trailing_zeroes(aStr);
			remove_trailing_zeroes(bStr);

			m_perimeter = 2 * (this->a + this->b);
			m_string_format = "rectangle " + aStr + " " + bStr;
		}

		double Rectangle::perimeter() const
		{
			return m_perimeter;
		}

		string Rectangle::toString() const
		{
			return m_string_format;
		}

		bool Rectangle::operator==(const Figure& other) const
		{
			const Rectangle* cast = dynamic_cast<const Rectangle*>(&other);
			if (!cast)
				return false;

			return abs(a - cast->a) < DBL_EPSILON && abs(b - cast->b) < DBL_EPSILON;
		}

		unique_ptr<Figure> Rectangle::clone() const
		{
			return make_unique<Rectangle>(*this);
		}
	}
}

