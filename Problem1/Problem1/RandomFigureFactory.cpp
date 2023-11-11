#include "RandomFigureFactory.h"
#include <ctime>

#include "Triangle.h"
#include "FigureType.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Utils.h"

using std::make_unique;

unique_ptr<Figure> RandomFigureFactory::create_figure(const string& args) const
{
	srand(time(nullptr)); // Seed for randomization

	// TODO: Extract magic numbers
	const FigureType figure_type = static_cast<FigureType>(rand() % 3);

	const double range_min = 1, range_max = 100;

	switch (figure_type)
	{
		case FigureType::TriangleType: {
			double a = generateRandomDoubleNumber(range_min, range_max);
			double b = generateRandomDoubleNumber(range_min, range_max);

			// The third side must be in the range (|a - b|, a + b)
			const double min_possible = abs(a - b);
			const double max_possible = a + b;

			double c = generateRandomDoubleNumber(min_possible, max_possible);

			return make_unique<Triangle>(a, b, c);
		}
		case FigureType::RectangleType: 
		{
			double a = generateRandomDoubleNumber(range_min, range_max);
			double b = generateRandomDoubleNumber(range_min, range_max);

			return make_unique<Rectangle>(a, b);
		}
		case FigureType::CircleType:
		{
			double radius = generateRandomDoubleNumber(range_min, range_max);
			return make_unique<Circle>(radius);
		}
	}
}
