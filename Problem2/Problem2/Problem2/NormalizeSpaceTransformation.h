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

			/**
			 * \brief Comparator - uses typeid
			 * \param other - the object the comparison is done against
			 * \return - true if types match, false otherwise
			 */
			bool operator==(const TextTransformation& other) const override;
			void add(shared_ptr<TextTransformation> transformation) override;
		};
	}
}

