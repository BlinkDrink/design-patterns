#pragma once
#include <string>

namespace Checksums
{
	namespace Messages
	{
		using std::string;

		class Message
		{
		public:
			virtual string what() const = 0;
			virtual ~Message() = default;
		};
	}
}
