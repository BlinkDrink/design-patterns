#include "FileMessage.h"

namespace Checksums
{
	namespace Messages
	{
		FileMessage::FileMessage(const string& fileName) : m_fileName(fileName)
		{

		}

		string FileMessage::what() const
		{
			return m_fileName;
		}
	}
}
