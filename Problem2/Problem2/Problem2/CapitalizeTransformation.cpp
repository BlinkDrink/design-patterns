#include "CapitalizeTransformation.h"

string CapitalizeTransformation::transform(const string& text) const
{
	string result(text);

	if (!result.empty() && isalpha(result[0]))
	{
		result[0] = toupper(result[0]);
	}

	return result;
}
