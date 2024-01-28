#pragma once
#include "VisitorBase.h"
#include "RegularFile.h"
#include "Directory.h"
#include "ChecksumCalculationBase.h"
#include "ObservableBase.h"


namespace Checksums
{
	namespace TreeElements
	{
		class RegularFile;
		class Directory;
	}

	namespace Visitors
	{
		using std::ostream;
		using std::unique_ptr;
		using std::shared_ptr;
		using ChecksumCalculations::ChecksumCalculationBase;
		using Observers::ObservableBase;
		using Observers::ObserverBase;
		using TreeElements::RegularFile;
		using TreeElements::Directory;


		/**
		 * \brief Concrete visitor used to traverse a given file tree and calculate the
		 * checksums of its files, then writes them to a given output stream. This class is also an observable
		 * that is used to update the progress bar shown on the output console.
		 */
		class HashStreamWriter : public VisitorBase, public ObservableBase
		{
		private:
			ostream& m_outputStream;
			unique_ptr<ChecksumCalculationBase> m_calculator;

		public:

			/**
			 * \brief Using dependency injection to set the output stream for the result and
			 * set the algorithm by which the checksum will be calculated
			 * \param output_stream - target stream where the checksums will be written
			 * \param calculator - the algorithm that will be used to calculate the checksums
			 */
			HashStreamWriter(ostream& output_stream, unique_ptr<ChecksumCalculationBase> calculator);

			/**
			 * \brief Adds the given observer to the list of observers that will be notified
			 * \param observer - observer object to be added
			 */
			void addObserver(shared_ptr<ObserverBase>& observer) override;

			/**
			 * \brief Method for handling the checksum calculation and writing to outputstream on a RegularFile.
			 */
			void visit(RegularFile& file) override;

			/**
			 * \brief Method for handling the checksum calculation and writing to outputstream on a Directory.
			 */
			void visit(Directory& directory) override;
		};
	}
}


