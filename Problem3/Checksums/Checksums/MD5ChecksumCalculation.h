#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		class MD5ChecksumCalculation : public ChecksumCalculationBase
		{
		public:
			string calculate(istream& input) const override;
		};
	}
}

