#pragma once
#include <string>
using std::string;
using std::unique_ptr;

// TODO: operator== here?
class Figure
{
public:
	virtual double perimeter() const = 0;
	virtual string toString() const = 0;
	virtual unique_ptr<Figure> clone() const = 0;
	virtual ~Figure() = default;
};
