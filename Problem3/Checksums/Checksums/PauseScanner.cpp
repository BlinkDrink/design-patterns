#include "PauseScanner.h"

#include <utility>

#include "FileMessage.h"

namespace Checksums
{
	namespace Scanners
	{
		PauseScanner::PauseScanner(shared_ptr<VisitorBase> visitor, shared_ptr<FileTreeElement> tree) : m_visitor(std::move(visitor)), m_fileTree(std::move(tree)), m_isPaused(false), m_isScanning(false)
		{

		}

		void PauseScanner::start()
		{
			m_isScanning = true;
			m_thread = std::make_unique<std::thread>([&]
				{
					m_fileTree->accept(*m_visitor);
				});
		}

		void PauseScanner::pause()
		{
			std::unique_lock lock(m_mutex);
			m_isPaused = true;
			notifyObservers(std::make_unique<Messages::FileMessage>("pause"));
		}

		void PauseScanner::resume()
		{
			std::unique_lock lock(m_mutex);
			m_isPaused = false;
			m_condition.notify_one();
			notifyObservers(std::make_unique<Messages::FileMessage>("resume"));
		}

		bool PauseScanner::isScanning() const
		{
			return m_isScanning;
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
