#pragma once
#include "TextTransformation .h"

namespace Problem2
{
	namespace TextTransformations
	{
		class RightTrimTransformation : public TextTransformation
		{
		public:

			/**
			 * \brief Remove one trailing whitespace from a given string
			 * \param text - the string whose whitespace will be removed(if any)
			 * \return - the newly transformed string
			 */
			string transform(string text) const override;
		};
	}
}
