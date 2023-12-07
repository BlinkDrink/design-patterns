#include "CapitalizeTransformation.h"

string CapitalizeTransformation::transform(string text) const
{
	if (!text.empty() && isalpha(text[0]))
	{
		text[0] = toupper(text[0]);
	}

	return text;
}
