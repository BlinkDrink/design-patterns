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

		/**
		 * \brief Base class for all Checksum calculation algorithms
		 */
		class ChecksumCalculationBase : public ObservableBase
		{
		public:
			virtual string calculate(istream& inputStream) const = 0;
			virtual ~ChecksumCalculationBase() = default;
		};
	}
}

