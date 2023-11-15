#pragma once
#include <random>

#include "FigureFactory.h"
#include "RandomGenerator.h"

namespace Problem1
{
	namespace Factories
	{
		using std::default_random_engine;
		using std::uniform_real_distribution;

		class RandomFigureFactory : public FigureFactory
		{
		private:
			//unique_ptr<RandomGenerator> _generator;

			default_random_engine m_re;
			uniform_real_distribution<double> m_generator;
		public:
			RandomFigureFactory(double lower_bound, double upper_bound, long long seed);

			/**
			 * \brief Create a random figure with random properties
			 * \return unique_ptr of the newly created figure
			 */
			unique_ptr<Figure> create_figure() override;
		};
	}
}
