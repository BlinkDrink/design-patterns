#pragma once
#include "FigureFactory.h"
#include "RandomGenerator.h"

namespace Problem1
{
	namespace Factories
	{
		class RandomFigureFactory : public FigureFactory
		{
		private:
			unique_ptr<RandomGenerator> _generator;
		public:
			RandomFigureFactory(RandomGenerator* rg);

			unique_ptr<Figure> create_figure() const override;
		};
	}
}
