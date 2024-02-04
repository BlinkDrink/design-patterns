#pragma once

#include<mutex>

#include "ChecksumCalculationBase.h"
#include "HashStreamWriterMemento.h"
#include "ObservableBase.h"
#include "VisitorBase.h"

namespace Checksums::Observers
{
	class ObserverBase;
}

namespace Checksums::Observers {
	class ObserverBase;
	class ObservableBase;
}

namespace Checksums::Mementos
{
	class HashStreamWriterMemento;
}

namespace Checksums::TreeElements
{
	class RegularFile;
	class Directory;
}

namespace Checksums::ChecksumCalculations
{
	class ChecksumCalculationBase;
}

namespace Checksums
{

	namespace Visitors
	{
		using std::mutex;
		using std::ostream;
		using std::ofstream;
		using std::unique_ptr;
		using std::shared_ptr;
		using std::condition_variable;

		/**
		 * \brief Concrete visitor used to traverse a given file tree and calculate the
		 * checksums of its files, then writes them to a given output stream. This class is also an observable
		 * that is used to update the progress bar shown on the output console.
		 */
		class HashStreamWriter : public VisitorBase, public Observers::ObservableBase, public Observers::ObserverBase
		{
		private:
			ostream& m_outputStream;
			ofstream m_fileStream;
			unique_ptr<ChecksumCalculations::ChecksumCalculationBase> m_calculator;
			unique_ptr<Mementos::HashStreamWriterMemento> m_state;

			mutex m_pauseMutex;
			condition_variable m_pauseCondition;
			bool m_isPaused = false;

			void checkForPause();
		public:

			/**
			 * \brief Using dependency injection to set the output stream for the result and
			 * set the algorithm by which the checksum will be calculated
			 * \param output_stream - target stream where the checksums will be written
			 * \param calculator - the algorithm that will be used to calculate the checksums
			 */
			HashStreamWriter(ostream& output_stream, unique_ptr<ChecksumCalculations::ChecksumCalculationBase> calculator);

			HashStreamWriter(ofstream&& output_stream, unique_ptr<ChecksumCalculations::ChecksumCalculationBase> calculator);

			/**
			 * \brief Adds the given observer to the list of observers that will be notified
			 * \param observer - observer object to be added
			 */
			void addObserver(shared_ptr<Observers::ObserverBase>& observer) override;

			/**
			 * \brief Method for handling the checksum calculation and writing to outputstream on a RegularFile.
			 */
			void visit(RegularFile& file) override;

			/**
			 * \brief Method for handling the checksum calculation and writing to outputstream on a Directory.
			 */
			void visit(Directory& directory) override;

			unique_ptr<Mementos::HashStreamWriterMemento> createMemento();
			void restoreFromMemento(unique_ptr<Mementos::HashStreamWriterMemento>& memento);
			void update(const ObservableBase& sender, shared_ptr<Messages::Message> msg) override;
		};
	}
}


