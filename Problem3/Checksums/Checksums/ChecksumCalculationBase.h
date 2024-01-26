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
			virtual string calculate(const string& path) const = 0;
			virtual ~ChecksumCalculationBase() = default;
		};
	}
}

