#pragma once
#include "TextTransformation.h"

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

			/**
			 * \brief Comparator - uses typeid
			 * \param other - the object the comparison is done against
			 * \return - true if types match, false otherwise
			 */
			bool operator==(const TextTransformation& other) const override;
			void add(unique_ptr<TextTransformation>& transformation) override;
		};
	}
}
