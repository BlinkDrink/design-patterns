#pragma once
#include <memory>
#include "Figure.h"
using std::unique_ptr;

namespace Problem1
{
	namespace Figures
	{
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
			virtual bool operator==(const Figure& other) const override final;

			/**
			 * \brief Used to clone object at run-time regardless of its type
			 * \return Dynamically allocated copy of the current object
			 */
			unique_ptr<Figure> clone() const override;

			/**
			 * \brief Figure Type
			 * \return - the FigureType matching Rectangle
			 */
			FigureType figureType() const override;
		};
	}
}