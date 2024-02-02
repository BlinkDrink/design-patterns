#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums::Visitors
{
	class HashStreamWriter;
}

namespace Checksums::ChecksumCalculations
{
	class ChecksumCalculationBase;
}

namespace Checksums
{
	namespace Mementos
	{
		using std::ostream;
		using std::streampos;
		using ChecksumCalculations::ChecksumCalculationBase;

		class HashStreamWriterMemento
		{
		private:
			streampos m_streamPosition;
			std::unique_ptr<ChecksumCalculationBase> m_calculator;
			friend Visitors::HashStreamWriter;
		public:
			HashStreamWriterMemento(streampos streamPosition, std::unique_ptr<ChecksumCalculations::ChecksumCalculationBase> calculator);
		};
	}
}


