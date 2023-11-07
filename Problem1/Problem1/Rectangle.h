#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
private:
	double a, b;
public:
	/**
	 * \brief Initializes the Rectangle figure by giving value to its two sides
	 * \param a First side
	 * \param b Second side
	 */
	Rectangle(double a, double b);

	/**
	 * \brief Calculates the perimeter of the rectangle
	 * \return Value of the calculated perimeter
	 */
	virtual double perimeter() const override final;

	/**
	 * \brief Stringifies the Rectangle figure
	 * \return string in format "rectangle a b" where a is the the value of the first side and b is the value of the second side
	 */
	virtual string toString() const override final;

	/**
	 * \brief Operator used to compare two rectangles
	 * \param other - rectangle that the comparison is done against
	 * \return 
	 */
	bool operator==(const Rectangle& other) const;
};