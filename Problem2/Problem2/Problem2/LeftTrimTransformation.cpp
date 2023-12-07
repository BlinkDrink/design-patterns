#include "LeftTrimTransformation.h"

string LeftTrimTransformation::transform(string text) const
{
	if (!text.empty() && (text[0] == ' ' || text[0] == '\t' || text[0] == '\n' || text[0] == '\r'))
	{
		text.erase(text.begin());
	}

	return text;
}
