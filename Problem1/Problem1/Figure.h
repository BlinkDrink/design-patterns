#pragma once
#include <string>
using std:: string;

class Figure 
{
public:
	virtual double perimeter() const = 0 ;
	virtual string toString() const = 0;
	virtual Figure* clone() const = 0;
	virtual ~Figure() = default;
};
