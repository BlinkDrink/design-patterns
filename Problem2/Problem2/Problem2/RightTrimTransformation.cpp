#include "RightTrimTransformation.h"

#include <vcruntime_typeinfo.h>

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

		bool RightTrimTransformation::operator==(const TextTransformation& other)
		{
			return typeid(*this) == typeid(other);
		}

		void RightTrimTransformation::add(unique_ptr<TextTransformation>& transformation)
		{
			// Does nothing unless it's CompositeTransformation
		}
	}
}
