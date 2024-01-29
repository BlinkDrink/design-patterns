#pragma once
#include "Message.h"

namespace Checksums
{
	namespace Messages
	{

		/**
		 * \brief Represents a simple message that carries information about how many bytes have been read
		 */
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



