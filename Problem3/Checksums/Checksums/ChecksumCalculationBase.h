#pragma once
#include <string>
#include<fstream>

#include "ObservableBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		using std::string;
		using std::istream;
		using Observers::ObservableBase;

		class ChecksumCalculationBase : public ObservableBase
		{
		public:
			virtual string calculate(const string& path) const = 0;
			virtual ~ChecksumCalculationBase() = default;
		};
	}
}

