#pragma once
#include <string>

#include "Message.h"

namespace Checksums::Observers
{
	class ObservableBase;
}

namespace Checksums
{
	namespace Observers
	{
		using std::string;
		using std::unique_ptr;
		using Messages::Message;

		/**
		 * \brief Base class for all observers that can update their state
		 * based on some notification data
		 */
		class ObserverBase
		{
		public:
			virtual void update(const ObservableBase& sender, std::shared_ptr<Message> msg) = 0;
			virtual ~ObserverBase() = default;
		};
	}
}
