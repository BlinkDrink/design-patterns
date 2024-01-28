#pragma once
#include <string>

#include "Message.h"

namespace Checksums
{
	namespace Observers
	{
		using std::string;
		using std::unique_ptr;
		using Messages::Message;

		class ObserverBase
		{
		public:
			virtual void update(unique_ptr<Message> msg) = 0;
			virtual ~ObserverBase() = default;
		};
	}
}
