#include "BytesMessage.h"

namespace Checksums
{
	namespace Messages
	{
		using std::to_string;

		BytesMessage::BytesMessage(size_t bytes) : m_bytes(bytes)
		{
		}

		string BytesMessage::what() const
		{
			return to_string(m_bytes);
		}
	}
}

