#pragma once

#include "TextTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		class CapitalizeTransformation : public TextTransformation
		{
		public:

			/**
			 * \brief Transforms a given string to it's capitalized first letter version
			 * \param text - input whose first letter will be capitalized(if possible)
			 * \return the newly formed string
			 */
			string transform(string text) const override;

			/**
			 * \brief Comparator - uses typeid
			 * \param other - the object comparison is done against
			 * \return - true if types match, false otherwise
			 */
			bool operator==(const TextTransformation& other) const override;
			void add(unique_ptr<TextTransformation>& transformation) override;
		};
	}
}


