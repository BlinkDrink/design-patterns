#pragma once
#include "Message.h"

namespace Checksums
{
	namespace Messages
	{

		/**
		 * \brief Represents a simple message that carries information about how many bytes have been read
		 */
		class BytesMessage : public Message
		{
		private:
			size_t m_bytes;
		public:
			BytesMessage(size_t bytes);
			string what() const override;
		};
	}
}



