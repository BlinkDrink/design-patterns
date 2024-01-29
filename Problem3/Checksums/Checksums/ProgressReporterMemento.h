#pragma once
#include <chrono>
#include <string>

namespace Checksums::Observers
{
	class ProgressReporter;
}

namespace Checksums
{
	namespace Mementos
	{
		using std::string;
		using std::chrono::steady_clock;

		class ProgressReporterMemento
		{
		private:
			size_t m_bytesRead;
			size_t m_totalBytes;
			string m_currentFile;
			size_t m_totalBytesToBeRead;
			mutable string m_previousMessage;
			steady_clock::time_point m_startTime;

			friend Observers::ProgressReporter;
		public:
			ProgressReporterMemento(size_t bytesRead, size_t totalBytes, string currentFile, size_t totalBytesToBeRead, string previousMessage, steady_clock::time_point startTime);
		};
	}
}
