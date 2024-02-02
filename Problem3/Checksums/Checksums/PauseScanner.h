#pragma once
#include <mutex>
#include <thread>

#include "FileTreeElement.h"
#include "ObservableBase.h"

namespace Checksums
{
	namespace Scanners
	{
		using std::mutex;
		using std::thread;
		using std::unique_ptr;
		using std::shared_ptr;
		using std::condition_variable;

		using Visitors::VisitorBase;
		using Observers::ObservableBase;
		using TreeElements::FileTreeElement;

		class PauseScanner : public ObservableBase
		{
		private:
			mutex m_mutex;
			unique_ptr<thread> m_thread;
			condition_variable m_condition;
			shared_ptr<VisitorBase> m_visitor;
			shared_ptr<FileTreeElement> m_fileTree;
			bool m_isPaused;
			bool m_isScanning;

		public:
			PauseScanner(shared_ptr<VisitorBase> visitor, shared_ptr<FileTreeElement> tree);

			void start();
			void pause();
			void resume();

			bool isScanning() const;
		};
	}
}
