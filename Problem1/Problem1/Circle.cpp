#define _USE_MATH_DEFINES
#include<cmath>
#include "Circle.h"
#include "Utils.h"
using std::to_string;

Circle::Circle(double radius) : radius(radius)
{
}

double Circle::perimeter() const
{
	return 2 * M_PI * radius;
}

string Circle::toString() const
{
	string r = to_string(radius);
	removeTrailingZeroes(r);
	return "circle " + r;
}

bool Circle::operator==(const Circle& other) const
{
	return abs(this->radius - other.radius) < DBL_EPSILON;
}
