#include "NormalizeSpaceTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		string NormalizeSpaceTransformation::transform(string text) const
		{
			size_t curr = 0;

			while (curr < text.size() - 1)
			{
				if (text[curr] == ' ' && text[curr + 1] == ' ')
				{
					text.erase(text.begin() + curr);
					curr--;
				}
				curr++;
			}

			return text;
		}
	}
}

