#pragma once
#include <memory>
#include "Figure.h"

using Problem1::Figures::Figure;
using std::unique_ptr;

namespace Problem1
{
	namespace Factories
	{
		/**
		 * \brief Abstract Factory for creating different types of figures depending on their input
		 */
		class FigureFactory {
		public:
			virtual unique_ptr<Figure> create_figure() = 0;
			virtual ~FigureFactory() = default;
		};
	}
}
