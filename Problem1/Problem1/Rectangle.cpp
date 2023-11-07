#include "Rectangle.h"
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
	return "rectangle " + to_string(a) + " " + to_string(b);
}

bool Rectangle::operator==(const Rectangle& other) const
{
	return abs(a - other.a)< DBL_EPSILON && abs(b- other.b) < DBL_EPSILON;
}

