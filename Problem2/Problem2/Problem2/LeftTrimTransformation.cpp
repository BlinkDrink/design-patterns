#include "LeftTrimTransformation.h"
#include <vcruntime_typeinfo.h>

namespace Problem2
{
	namespace TextTransformations
	{
		string LeftTrimTransformation::transform(string text) const
		{
			if (!text.empty() && (text[0] == ' ' || text[0] == '\t' || text[0] == '\n' || text[0] == '\r'))
			{
				text.erase(text.begin());
			}

			return text;
		}

		bool LeftTrimTransformation::operator==(const TextTransformation& other)
		{
			return typeid(*this) == typeid(other);
		}

		void LeftTrimTransformation::add(unique_ptr<TextTransformation>& transformation)
		{
			// Does nothing unless it's CompositeTransformation
		}
	}
}


