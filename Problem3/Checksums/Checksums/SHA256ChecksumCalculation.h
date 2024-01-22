#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		class SHA256ChecksumCalculation : public ChecksumCalculationBase
		{
		public:
			string calculate(istream& input) const override;
		};
	}
}

