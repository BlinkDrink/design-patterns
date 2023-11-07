#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
private:
	const double a, b;
public:
	Rectangle(double a, double b);
	virtual double perimeter() const override final;
	virtual string toString() const override final;
};