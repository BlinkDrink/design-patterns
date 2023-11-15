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
	using std::invalid_argument;
	using std::swap;

	namespace Factories
	{
		RandomFigureFactory::RandomFigureFactory(double lower_bound = DBL_EPSILON, double upper_bound = 100, long long seed = time(nullptr)) : m_re(seed)
		{
			if (lower_bound <= 0 || upper_bound <= 0)
				throw invalid_argument("Lower or upper bound cannot be non-positive");

			if (lower_bound > upper_bound)
				throw invalid_argument("Lower bound cannot be greater than the upper bound");

			m_dgenerator = uniform_real_distribution<double>(lower_bound, upper_bound);
			m_igenerator = uniform_int_distribution<int>(floor(lower_bound), ceil(upper_bound));
		}

		unique_ptr<Figure> RandomFigureFactory::create_figure()
		{
			const FigureType figure_type = static_cast<FigureType>(m_igenerator(m_re) % 3);

			switch (figure_type)
			{
			case FigureType::TriangleType: {
				double a = m_dgenerator(m_re);
				double b = m_dgenerator(m_re);

				// The third side must be in the range (|a - b|, a + b)
				const double min_possible = abs(a - b);
				const double max_possible = a + b;

				double c = m_dgenerator(m_re);

				c = max(c, min_possible);
				c = min(c, max_possible);

				return make_unique<Triangle>(a, b, c);
			}
			case FigureType::RectangleType:
			{
				double a = m_dgenerator(m_re);
				double b = m_dgenerator(m_re);

				return make_unique<Rectangle>(a, b);
			}
			case FigureType::CircleType:
			{
				double radius = m_dgenerator(m_re);
				return make_unique<Circle>(radius);
			}
			}

			throw std::invalid_argument("Invalid figure type");
		}
	}
}
