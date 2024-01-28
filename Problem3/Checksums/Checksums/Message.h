#pragma once
#include <string>

namespace Checksums
{
	namespace Messages
	{
		using std::string;

		/**
		 * \brief Base class for the types of messages observables can send
		 */
		class Message
		{
		public:
			virtual string what() const = 0;
			virtual ~Message() = default;
		};
	}
}
