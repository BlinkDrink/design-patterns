#pragma once
#include "Figure.h"

class Circle : public Figure
{
private:
	double radius;
public:
	Circle(double radius);
	virtual double perimeter() const override final;
	virtual string toString() const override final;
	bool operator==(const Circle& other) const;
};