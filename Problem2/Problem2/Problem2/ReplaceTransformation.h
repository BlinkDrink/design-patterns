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
			 * \brief Replaces (case-sensitive) all occurrences of the string A with the string B, e.g.
			 *	if A="abc" and B="d", then " abc_abcdef" becomes " d_ddef"
			 * \param text - string on which replacement will be performed
			 * \return - the newly transformed string
			 */
			string transform(string text) const override;

			ReplaceTransformation(string from, string to);
		};
	}
}


