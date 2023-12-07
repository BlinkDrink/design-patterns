#include "RightTrimTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		string RightTrimTransformation::transform(string text) const
		{
			if (!text.empty() && (text.back() == ' ' || text.back() == '\t' || text.back() == '\n' || text.back() == '\r'))
			{
				text.pop_back();
			}

			return text;
		}
	}
}
