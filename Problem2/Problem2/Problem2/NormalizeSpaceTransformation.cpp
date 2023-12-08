#include "NormalizeSpaceTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		string NormalizeSpaceTransformation::transform(string text) const
		{
			size_t write_pos = 0;
			bool space_window = false;

			for (size_t i = 0; i < text.size(); ++i)
			{
				if (text[i] == ' ')
				{
					if (!space_window)
					{
						text[write_pos++] = text[i];
						space_window = true;
					}
				}
				else
				{
					text[write_pos++] = text[i];
					space_window = false;
				}
			}

			text.erase(write_pos);
			return text;
		}
	}
}

