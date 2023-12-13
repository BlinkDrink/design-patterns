#include "DecorateTransformation.h"

#include <vcruntime_typeinfo.h>

namespace Problem2
{
	namespace TextTransformations
	{
		string DecorateTransformation::transform(string text) const
		{
			return "-={ " + text + " }=-";
		}

		bool DecorateTransformation::operator==(const TextTransformation& other)
		{
			return typeid(*this) == typeid(other);
		}

		void DecorateTransformation::add(unique_ptr<TextTransformation>& transformation)
		{
			// Does nothing unless it's CompositeTransformation
		}
	}
}

