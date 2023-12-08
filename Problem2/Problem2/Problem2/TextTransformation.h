#pragma once
#include <string>

using std::string;

namespace Problem2
{
	namespace TextTransformations
	{

		/**
		 * \brief Base class for the different algorithms we can apply to a label
		 */
		class TextTransformation
		{
		public:
			virtual string transform(string text) const = 0;
			virtual ~TextTransformation() = default;
		};
	}
}
