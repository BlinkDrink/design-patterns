#include "ProgressReporterMemento.h"

namespace Checksums
{
	namespace Mementos
	{
		ProgressReporterMemento::ProgressReporterMemento(size_t bytesRead, size_t totalBytes, string currentFile,
			size_t totalBytesToBeRead, string previousMessage, steady_clock::time_point startTime) : m_bytesRead(bytesRead), m_totalBytes(totalBytes), m_currentFile(std::move(currentFile)), m_totalBytesToBeRead(totalBytesToBeRead), m_previousMessage(std::move(previousMessage)), m_startTime(startTime)
		{
		}
	}
}
