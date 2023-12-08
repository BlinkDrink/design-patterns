#pragma once
#include "TextTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		class NormalizeSpaceTransformation : public TextTransformation
		{
		public:
			/**
			 * \brief Merge consecutive occurrences of space into one occurrence
			 * \param text - string whose spaces will be merged
			 * \return - the newly transformed string
			 */
			string transform(string text) const override;
		};
	}
}

