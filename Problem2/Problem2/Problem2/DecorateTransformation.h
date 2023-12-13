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

			/**
			 * \brief Comparator - uses typeid
			 * \param other - the object comparison is done against
			 * \return - true if types match, false otherwise
			 */
			bool operator==(const TextTransformation& other) override;
			void add(unique_ptr<TextTransformation>& transformation) override;
		};
	}
}

