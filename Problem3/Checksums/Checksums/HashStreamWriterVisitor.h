#pragma once
#include "VisitorBase.h"
#include "RegularFile.h"
#include "Directory.h"
#include "ChecksumCalculationBase.h"


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
		using ChecksumCalculations::ChecksumCalculationBase;
		using TreeElements::RegularFile;
		using TreeElements::Directory;


		class HashStreamWriterVisitor : public VisitorBase
		{
		private:
			ostream& m_outputStream;
			unique_ptr<ChecksumCalculationBase> m_calculator;

		public:
			HashStreamWriterVisitor(ostream& m_output_stream, unique_ptr<ChecksumCalculationBase> calculator);
			void visit(RegularFile& file) override;
			void visit(Directory& directory) override;
		};
	}
}


