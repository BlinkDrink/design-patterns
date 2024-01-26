#pragma once
#include "ChecksumCalculationBase.h"
#include "VisitorBase.h"

namespace Checksums
{
	namespace Visitors
	{
		using std::ostream;
		using std::unique_ptr;
		using ChecksumCalculations::ChecksumCalculationBase;


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


