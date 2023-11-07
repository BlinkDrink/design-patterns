#include "Triangle.h"
using std::to_string;

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c)
{
}

double Triangle::perimeter() const
{
	return a + b + c;
}

string Triangle::toString() const
{
	return "triangle " + to_string(a) + " " + to_string(b) + " " + to_string(c);
}
