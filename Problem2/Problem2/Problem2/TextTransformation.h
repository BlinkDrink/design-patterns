#pragma once
#include <string>

using std::string;

namespace Problem2
{
	namespace TextTransformations
	{
		class TextTransformation
		{
		public:
			virtual string transform(string text) const = 0;
			virtual ~TextTransformation() = default;
		};
	}
}
