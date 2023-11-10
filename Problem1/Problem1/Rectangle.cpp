#include "Rectangle.h"
#include "Utils.h"
using std::to_string;
using std::swap;

Rectangle::Rectangle(double a, double b)
{
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

	removeTrailingZeroes(aStr);
	removeTrailingZeroes(bStr);

	return "rectangle " + aStr + " " + bStr;
}

bool Rectangle::operator==(const Rectangle& other) const
{
	return abs(a - other.a)< DBL_EPSILON && abs(b- other.b) < DBL_EPSILON;
}

Rectangle* Rectangle::clone() const
{
	return new Rectangle(*this);
}

