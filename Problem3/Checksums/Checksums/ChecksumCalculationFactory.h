#pragma once
#include <memory>

#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace Factories
	{
		using std::unique_ptr;
		using ChecksumCalculations::ChecksumCalculationBase;

		class ChecksumCalculationFactory
		{
		public:
			virtual unique_ptr<ChecksumCalculationBase> create_calculator() = 0;
			virtual ~ChecksumCalculationFactory() = default;
		};
	}
}
