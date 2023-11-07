#pragma once
#include "Figure.h"
using std::string;

class Triangle : public Figure
{
private:
	const double a, b, c;
public:
	Triangle(double a, double b, double c);
	virtual double perimeter() override;
	virtual string toString() override;
};