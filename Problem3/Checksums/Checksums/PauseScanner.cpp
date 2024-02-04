#include "PauseScanner.h"

#include <utility>

#include "FileMessage.h"

namespace Checksums
{
	namespace Scanners
	{
		PauseScanner::PauseScanner(shared_ptr<VisitorBase> visitor, shared_ptr<FileTreeElement> tree) : m_visitor(visitor), m_fileTree(tree), m_isPaused(false), m_isScanning(false)
		{

		}

		PauseScanner::PauseScanner(PauseScanner&& other) noexcept
			: m_visitor(std::move(other.m_visitor)),
			m_fileTree(std::move(other.m_fileTree)),
			m_isPaused(other.m_isPaused.load()),
			m_isScanning(other.m_isScanning.load())
		{
			m_thread = std::move(other.m_thread);
		}

		PauseScanner& PauseScanner::operator=(PauseScanner&& other) noexcept
		{
			if (this != &other)
			{
				m_visitor = std::move(other.m_visitor);
				m_fileTree = std::move(other.m_fileTree);
				m_isPaused.store(other.m_isPaused.load());
				m_isScanning.store(other.m_isScanning.load());
				m_thread = std::move(other.m_thread);
			}
			return *this;
		}

		PauseScanner::~PauseScanner() {
			if (m_thread.joinable()) {
				m_thread.join();
			}
		}

		void PauseScanner::start()
		{
			m_isScanning = true;
			m_thread = std::thread([this]
				{
					m_fileTree->accept(*m_visitor);
				});
		}

		void PauseScanner::pause()
		{
			std::unique_lock<std::mutex> lock(m_mutex);
			m_isPaused = true;
			notifyObservers(std::make_unique<Messages::FileMessage>("pause"));
		}

		void PauseScanner::resume()
		{
			{
				std::unique_lock<std::mutex> lock(m_mutex);
				m_isPaused = false;
			}
			m_condition.notify_one();

			notifyObservers(std::make_unique<Messages::FileMessage>("resume"));
		}

		bool PauseScanner::isScanning() const
		{
			return m_isScanning.load();
		}

		bool PauseScanner::isPaused() const
		{
			return m_isPaused.load();
		}
	}
}
