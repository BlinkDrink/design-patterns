#pragma once
#include <chrono>
#include <memory>

#include "ObserverBase.h"
#include "ProgressReporterMemento.h"

namespace Checksums::Mementos
{
	class ProgressBarMemento;
}

namespace Checksums
{
	namespace Observers
	{
		using std::chrono::steady_clock;

		/**
		 * \brief Represents the progress bar in the application.
		 * This is an observer that listens for notifications from HashStreamWriter(Observable) and
		 * updates its state accordingly.
		 */
		class ProgressReporter : public ObserverBase
		{
		private:
			size_t m_bytesRead; // Bytes read on each update call (if any)
			size_t m_totalBytes; // Total bytes read through the lifetime of the object
			string m_currentFile; // The path to the current file that is being processed
			size_t m_totalBytesToBeRead; // The total size of the file tree in bytes
			mutable string m_previousMessage; // the previously printed progress output by the progress bar
			steady_clock::time_point m_startTime; // the time of initialization of the progress bar
			unique_ptr<Mementos::ProgressReporterMemento> m_state;
		public:
			ProgressReporter(size_t totalBytes);

			/**
			 * \brief Given a Message object, this method determines whether the message
			 * contains information of the file that is to be processed or the bytes that have
			 * been read from a file that is being processed. After which updates the progress bar
			 * accordingly
			 * \param msg - message object that carries information about the file's path or the bytes read.
			 */
			void update(const ObservableBase& sender, std::shared_ptr<Message> msg) override;

			void display() const;

			unique_ptr<Mementos::ProgressReporterMemento> createMemento() const;
			void restoreFromMemento(unique_ptr<Mementos::ProgressReporterMemento>& memento);
		};
	}
}
