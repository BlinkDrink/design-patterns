#define _USE_MATH_DEFINES
#include<cmath>
#include "Circle.h"
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
	return "circle " + to_string(radius);
}
