#pragma once
#include "Figure.h"

class Circle : public Figure
{
private:
	const double radius;
public:
	Circle(double radius);
	virtual double perimeter() const override;
	virtual string toString() const override;
};