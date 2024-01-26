#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		class MD5ChecksumCalculation : public ChecksumCalculationBase
		{
		public:
			string calculate(const string& path) const override;
		};
	}
}

