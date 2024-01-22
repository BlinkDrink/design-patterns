#pragma once
#include <string>
#include<fstream>

namespace Checksums
{
	namespace ChecksumCalculations
	{
		using std::string;
		using std::istream;

		class ChecksumCalculationBase
		{
		public:
			virtual string calculate(istream& input) const = 0;
			virtual ~ChecksumCalculationBase() = default;
		};
	}
}

