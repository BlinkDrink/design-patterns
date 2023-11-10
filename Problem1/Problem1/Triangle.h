#pragma once
#include "Figure.h"
using std::string;

class Triangle : public Figure
{
private:
	double a, b, c;
public:
	/**
	 * \brief Initializes the triangle figure with 3 values each representing a side of the triangle.
	 * Also sorts the values in such a way that the lowest value is stored in this->a, the second lowest is
	 * stored in this->b and the last value is stored in this->c
	 * \param a First side
	 * \param b Second side
	 * \param c Third side
	 */
	Triangle(double a, double b, double c);

	/**
	 * \brief Calculates the perimeter of the triangle
	 * \return the calculated value for the perimeter
	 */
	virtual double perimeter() const override;

	/**
	 * \brief Stringifies the triangle figure
	 * \return string in format "triangle a b c" where a,b and c are the data members
	 */
	virtual string toString() const override;

	/**
	 * \brief Operator used to compare triangles
	 * \param other - the figure that the comparison is done against
	 * \return true if they match on all three data members, false otherwise
	 */
	bool operator==(const Triangle& other) const;

	/**
	 * \brief Used to clone object at run-time regardless of its type
	 * \return Dynamically allocated copy of the current object
	 */
	Triangle* clone() const override;
};