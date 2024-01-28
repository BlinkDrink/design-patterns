#pragma once
#include <chrono>
#include <memory>

#include "ObserverBase.h"

namespace Checksums
{
	namespace Observers
	{
		using std::chrono::steady_clock;

		class ProgressReporter : public ObserverBase
		{
		private:
			size_t m_bytesRead;
			size_t m_totalBytes;
			string m_currentFile;
			size_t m_totalBytesToBeRead;
			mutable string m_previousMessage;
			steady_clock::time_point m_startTime;
			bool m_hasWrittenYet;
		public:
			ProgressReporter(size_t totalBytes);
			void update(unique_ptr<Message> msg) override;
			void display() const;
		};
	}
}