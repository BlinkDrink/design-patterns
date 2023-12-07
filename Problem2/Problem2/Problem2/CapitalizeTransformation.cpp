#include "CapitalizeTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		string CapitalizeTransformation::transform(string text) const
		{
			if (!text.empty() && isalpha(text[0]))
			{
				text[0] = toupper(text[0]);
			}

			return text;
		}
	}
}
