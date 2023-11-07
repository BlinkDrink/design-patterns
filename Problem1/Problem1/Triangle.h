#pragma once
#include "Figure.h"
using std::string;

class Triangle : public Figure
{
private:
	double a, b, c;
public:
	Triangle(double a, double b, double c);
	virtual double perimeter() const override;
	virtual string toString() const override;
	bool operator==(const Triangle& other) const;
};