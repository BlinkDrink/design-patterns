#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace Factories
	{
		using std::ifstream;
		using std::istream;

		class ChecksumCalculationFactory
		{
		private:
			ifstream m_file;
			istream& m_stream;
		public:
			ChecksumCalculationFactory(istream& stream);
			ChecksumCalculationFactory(ifstream&& fileStream);
			std::unique_ptr<ChecksumCalculations::ChecksumCalculationBase> create_calculator();
		};
	}
}


