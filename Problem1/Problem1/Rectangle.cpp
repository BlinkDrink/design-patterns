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
	string aStr = to_string(a);
	string bStr = to_string(b);
	bStr.erase(aStr.find_last_not_of('0') + 1, std::string::npos);
	bStr.erase(bStr.find_last_not_of('0') + 1, std::string::npos);

	return "rectangle " + aStr + " " + bStr;
}

bool Rectangle::operator==(const Rectangle& other) const
{
	return abs(a - other.a)< DBL_EPSILON && abs(b- other.b) < DBL_EPSILON;
}

