#include "DecorateTransformation.h"

namespace Problem2
{
	namespace TextTransformations
	{
		string DecorateTransformation::transform(string text) const
		{
			return "-={ " + text + " }=-";
		}
	}
}

