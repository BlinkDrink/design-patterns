#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		class SHA256ChecksumCalculation : public ChecksumCalculationBase
		{
		public:
			string calculate(const string& path) const override;
		};
	}
}

