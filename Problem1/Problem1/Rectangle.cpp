#include "Rectangle.h"
using std::to_string;

Rectangle::Rectangle(double a, double b) : a(a), b(b)
{
}

double Rectangle::perimeter() const
{
	return 2 * (a + b);
}

string Rectangle::toString() const
{
	return "rectangle " + to_string(a) + " " + to_string(b);
}

