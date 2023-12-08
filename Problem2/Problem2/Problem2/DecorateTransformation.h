#pragma once

#include "TextTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		class DecorateTransformation : public TextTransformation
		{
		public:

			/**
			 * \brief Bracket the given text with "-={" and "}=-"
			 * \param text - the string to be bracketed
			 * \return - the newly transformed string
			 */
			string transform(string text) const override;
		};
	}
}

