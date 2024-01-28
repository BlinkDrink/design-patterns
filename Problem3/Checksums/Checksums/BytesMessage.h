#pragma once
#include "Message.h"

namespace Checksums
{
	namespace Messages
	{
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



