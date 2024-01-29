#pragma once
#include "ChecksumCalculationFactory.h"

namespace Checksums
{
	namespace Factories
	{
		using std::ifstream;
		using std::istream;

		class StreamChecksumCalculationFactory : public ChecksumCalculationFactory
		{
		private:
			ifstream m_file;
			istream& m_stream;
		public:
			StreamChecksumCalculationFactory(istream& stream);
			StreamChecksumCalculationFactory(ifstream&& fileStream);
			unique_ptr<ChecksumCalculationBase> create_calculator() override;
		};
	}
}


