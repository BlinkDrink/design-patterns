#pragma once
#include "Message.h"

namespace Checksums
{
	namespace Messages
	{
		class ScannerMessage : public Message
		{
		private:
			string m_currentState;
		public:
			ScannerMessage(string currentState);
			string what() const override;
		};
	}
}



