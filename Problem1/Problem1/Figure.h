#pragma once
#include <string>

class Figure
{
public:
	virtual double perimeter() = 0;
	virtual std::string toString() = 0;
};
