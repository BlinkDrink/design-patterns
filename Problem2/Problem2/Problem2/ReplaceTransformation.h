#pragma once
#include "TextTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		class ReplaceTransformation : public TextTransformation
		{
		private:
			string from;
			string to;
		public:
			/**
			 * \brief Replaces (case-sensitive) all occurrences of the string from with the string to, e.g.
			 *	if from="abc" and to="d", then " abc_abcdef" becomes " d_ddef"
			 * \param text - string on which replacement will be performed
			 * \return - the newly transformed string
			 */
			string transform(string text) const override;

			ReplaceTransformation(string from, string to);

			/**
			 * \brief Comparator - uses dynamic_cast
			 * \param other - the object the comparison is done against
			 * \return - true if object types, data member from and data member to match, false otherwise
			 */
			bool operator==(const TextTransformation& other) const override;
			void add(unique_ptr<TextTransformation>& transformation) override;
		};
	}
}


