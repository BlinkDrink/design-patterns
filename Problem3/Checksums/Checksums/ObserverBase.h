#pragma once
#include <string>

namespace Checksums
{
	namespace Observers
	{
		using std::string;

		class ObserverBase
		{
		public:
			virtual void update(const string& fileName) = 0;
			virtual ~ObserverBase() = default;
		};
	}
}
