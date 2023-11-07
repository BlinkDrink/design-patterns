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
	bStr.erase(aStr.find_last_not_of('0') + 1, std::string::npos);
	bStr.erase(bStr.find_last_not_of('0') + 1, std::string::npos);
	cStr.erase(cStr.find_last_not_of('0') + 1, std::string::npos);

	return "triangle " + aStr + " " + bStr + " " + cStr;
}

bool Triangle::operator==(const Triangle& other) const
{
	return abs(a - other.a) < DBL_EPSILON && abs(b - other.b) < DBL_EPSILON && abs(c - other.c) < DBL_EPSILON; 
}
