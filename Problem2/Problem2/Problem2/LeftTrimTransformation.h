#pragma once
#include "TextTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		class LeftTrimTransformation : public TextTransformation
		{
		public:
			/**
			 * \brief Remove one leading whitespace from a string
			 * \param text - string whose whitespace will be removed(if any)
			 * \return - the newly transformed string
			 */
			string transform(string text) const override;
		};
	}
}
