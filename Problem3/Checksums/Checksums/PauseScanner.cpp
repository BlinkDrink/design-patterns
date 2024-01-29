#include "PauseScanner.h"

namespace Checksums
{
	namespace Scanners
	{
		PauseScanner::PauseScanner() : m_isPaused(false)
		{
		}

		void PauseScanner::start()
		{

		}

		void PauseScanner::pause()
		{
			std::unique_lock<std::mutex> lock(m_mutex);
			m_isPaused = true;
		}

		void PauseScanner::resume()
		{
			std::unique_lock lock(m_mutex);
			m_isPaused = false;
			m_condition.notify_one();
		}

		void PauseScanner::stop()
		{
		}

		//void PauseScanner::setFileTree(unique_ptr<TreeElements::FileTreeElement> tree)
		//{
		//	m_fileTree = std::move(tree);
		//}

		//void PauseScanner::setVisitor(unique_ptr<Visitors::VisitorBase> visitor)
		//{
		//	m_visitor = std::move(visitor);
		//	ObservableBase::addObserver(visitor);
		//}
	}
}
