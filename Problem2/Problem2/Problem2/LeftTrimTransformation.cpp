#include "LeftTrimTransformation.h"

string LeftTrimTransformation::transform(string text) const
{
	if (!text.empty() && text[0] == ' ')
	{
		text.erase(text.begin());
	}

	return text;
}
