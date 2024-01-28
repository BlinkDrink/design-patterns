#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		using Observers::ObserverBase;

		class MD5ChecksumCalculation : public ChecksumCalculationBase
		{
		public:
			string calculate(const string& path) const override;
		};
	}
}

