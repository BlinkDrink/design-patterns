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
			thread m_thread;
			condition_variable m_condition;
			shared_ptr<VisitorBase> m_visitor;
			shared_ptr<FileTreeElement> m_fileTree;
			std::atomic<bool> m_isPaused;
			std::atomic<bool> m_isScanning;

		public:
			PauseScanner(shared_ptr<VisitorBase> visitor, shared_ptr<FileTreeElement> tree);

			PauseScanner(const PauseScanner& other) = delete;
			PauseScanner& operator=(const PauseScanner& other) = delete;

			PauseScanner(PauseScanner&& other) noexcept;
			PauseScanner& operator=(PauseScanner&& other) noexcept;

			void start();
			void pause();
			void resume();
			bool isScanning() const;
			bool isPaused() const;
			~PauseScanner();
		};
	}
}
