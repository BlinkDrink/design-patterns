#include "CapitalizeTransformation.h"

#include <vcruntime_typeinfo.h>

namespace Problem2
{
	namespace TextTransformations
	{
		string CapitalizeTransformation::transform(string text) const
		{
			if (!text.empty() && isalpha(text[0]))
			{
				text[0] = toupper(text[0]);
			}

			return text;
		}

		bool CapitalizeTransformation::operator==(const TextTransformation& other) const
		{
			return typeid(*this) == typeid(other);
		}

		void CapitalizeTransformation::add(shared_ptr<TextTransformation> transformation)
		{
			// Does nothing unless it's CompositeTransformation
		}
	}
}
