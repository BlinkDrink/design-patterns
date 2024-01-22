#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		class SHA2ChecksumCalculation : public ChecksumCalculationBase
		{
		public:
			string calculate(istream& input) const override;
		};
	}
}

