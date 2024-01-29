#pragma once
#include <mutex>

#include "ChecksumCalculationBase.h"
#include "FileTreeElement.h"
#include "ObservableBase.h"

namespace Checksums
{
	namespace Scanners
	{
		using std::mutex;
		using std::unique_ptr;
		using std::condition_variable;

		class PauseScanner : public Observers::ObservableBase
		{
		private:
			mutex m_mutex;
			condition_variable m_condition;
			unique_ptr<Visitors::VisitorBase> m_visitor;
			unique_ptr<TreeElements::FileTreeElement> m_fileTree;
			bool m_isPaused;

		public:
			PauseScanner();

			void start();
			void pause();
			void resume();
			void stop();


		};
	}
}
