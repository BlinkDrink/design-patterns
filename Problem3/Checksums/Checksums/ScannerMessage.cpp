#include "ScannerMessage.h"

namespace Checksums
{
	namespace Messages
	{
		ScannerMessage::ScannerMessage(string currentState) : m_currentState(std::move(currentState))
		{
		}

		string ScannerMessage::what() const
		{
			return m_currentState;
		}
	}
}

