#pragma once
#include <random>

#include "FigureFactory.h"

namespace Problem1
{
	namespace Factories
	{
		using std::default_random_engine;
		using std::uniform_real_distribution;
		using std::random_device;
		using std::mt19937;
		using std::uniform_int_distribution;

		class RandomFigureFactory : public FigureFactory
		{
		private:
			default_random_engine m_re;
			uniform_real_distribution<double> m_dgenerator;
			uniform_int_distribution<int> m_igenerator;
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
