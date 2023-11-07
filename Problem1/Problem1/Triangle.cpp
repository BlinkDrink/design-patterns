#include "Triangle.h"
#include <stdexcept>
using std::invalid_argument;
using std::to_string;
using std::swap;

Triangle::Triangle(double a, double b, double c)
{
	if (a + b < c || b + c < a || a + c < b)
		throw invalid_argument("Invalid triangle");

	this->a = a;
	this->b = b;
	this->c = c;

	if (a > b)
		swap(a, b);
	if (a > c)
		swap(a, c);
	if (b > c)
		swap(b, c);
}

double Triangle::perimeter() const
{
	return a + b + c;
}

string Triangle::toString() const
{
	return "triangle " + to_string(a) + " " + to_string(b) + " " + to_string(c);
}

bool Triangle::operator==(const Triangle& other) const
{
	return abs(a - other.a) < DBL_EPSILON && abs(b - other.b) < DBL_EPSILON && abs(c - other.c) < DBL_EPSILON; 
}
