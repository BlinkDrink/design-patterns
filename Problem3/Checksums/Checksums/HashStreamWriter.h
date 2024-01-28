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


		class HashStreamWriter : public VisitorBase, public ObservableBase
		{
		private:
			ostream& m_outputStream;
			unique_ptr<ChecksumCalculationBase> m_calculator;

		public:
			HashStreamWriter(ostream& output_stream, unique_ptr<ChecksumCalculationBase> calculator);
			void addObserver(shared_ptr<ObserverBase>& observer) override;
			void visit(RegularFile& file) override;
			void visit(Directory& directory) override;
		};
	}
}


