#include "RandomFigureFactory.h"
#include "Triangle.h"
#include "FigureType.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Utils.h"

using std::make_unique;

namespace Problem1
{
	using Figures::Rectangle;
	using Figures::Circle;
	using Figures::Triangle;
	using std::max;
	using std::min;

	namespace Factories
	{

		RandomFigureFactory::RandomFigureFactory(double lower_bound = DBL_EPSILON, double upper_bound = 100, long long seed = time(nullptr)) : m_re(seed), m_generator(lower_bound, upper_bound)
		{
			srand(seed);
		}

		unique_ptr<Figure> RandomFigureFactory::create_figure()
		{
			const FigureType figure_type = static_cast<FigureType>(rand() % 3);

			switch (figure_type)
			{
			case FigureType::TriangleType: {
				double a = m_generator(m_re);
				double b = m_generator(m_re);

				// The third side must be in the range (|a - b|, a + b)
				const double min_possible = abs(a - b); // 10
				const double max_possible = a + b; // 50

				double c = m_generator(m_re) * (max_possible - min_possible) + min_possible;
				c = max(c, min_possible);
				c = min(c, max_possible);

				return make_unique<Triangle>(a, b, c);
			}
			case FigureType::RectangleType:
			{
				double a = m_generator(m_re);
				double b = m_generator(m_re);

				return make_unique<Rectangle>(a, b);
			}
			case FigureType::CircleType:
			{
				double radius = m_generator(m_re);
				return make_unique<Circle>(radius);
			}
			}

			throw std::invalid_argument("Invalid figure type");
		}
	}
}
