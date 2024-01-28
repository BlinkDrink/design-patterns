#pragma once
#include <memory>

#include "ObserverBase.h"

namespace Checksums
{
	namespace Observers
	{
		class ProgressReporter : public ObserverBase
		{
		private:
			string m_currentFile;
			size_t m_bytesRead = 0;
			bool m_hasWrittenYet = false;
		public:
			void update(unique_ptr<Message> msg) override;
			void display() const;
		};
	}
}