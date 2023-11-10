#pragma once
#include "Figure.h"

class Circle : public Figure
{
private:
	double radius;
public:
	/**
	 * \brief Initializes the Circle figure with the given radius
	 * \param radius - the radius of the circle
	 */
	Circle(double radius);

	/**
	 * \brief Calculates the perimeter of the circle
	 * \return Value of the calculated perimeter
	 */
	virtual double perimeter() const override final;

	/**
	 * \brief Stringifies the circle figure
	 * \return string in format "circle radius" where radius is the data member representing the radius number
	 */
	virtual string toString() const override final;

	/**
	 * \brief Operator used to compare circles
	 * \param other - the figure that the comparison is done against
	 * \return true if the circles' radiuses match, false otherwise
	 */
	bool operator==(const Circle& other) const;

	/**
	 * \brief Used to clone object at run-time regardless of its type
	 * \return Dynamically allocated copy of the current object
	 */
	Circle* clone() const override;
};