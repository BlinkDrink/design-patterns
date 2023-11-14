#pragma once
#include <memory>
#include "FigureFactory.h"
using std::unique_ptr;

namespace Problem1
{
	namespace Factories
	{
		class InputFactory
		{
		public:
			/**
			 * \brief Method used for creation of the appropriate figure factory based on the input type
			 * \param inputType - the name of the input type that will be used for creating a figure
			 * \return - concrete figure factory
			 */
			virtual unique_ptr<FigureFactory> create_figure_factory(const string& inputType) const = 0;
			virtual ~InputFactory() = default;
		};
	}
}

