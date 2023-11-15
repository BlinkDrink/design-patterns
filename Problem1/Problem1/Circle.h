#pragma once
#include <memory>
#include "Figure.h"

using std::unique_ptr;

namespace Problem1
{
	namespace Figures
	{

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
			 * \brief Operator used to compare circle with a given figure
			 * \param other - the figure that the comparison is done against
			 * \return true if both figures are circle and have equal radiuses, false otherwise
			 */
			virtual bool operator==(const Figure& other) const override;

			/**
			 * \brief Used to clone object at run-time regardless of its type
			 * \return Dynamically allocated copy of the current object
			 */
			virtual unique_ptr<Figure> clone() const override;

			/**
			 * \brief Figure Type
			 * \return - the FigureType matching Circle
			 */
			FigureType figureType() const override;
		};
	}
}
