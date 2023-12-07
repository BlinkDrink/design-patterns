#pragma once
#include <string>

using std::string;

namespace Problem2
{
	namespace Labels
	{
		class Label
		{
		public:
			virtual string getText() const = 0;
			virtual ~Label() = default;
		};
	}
}
