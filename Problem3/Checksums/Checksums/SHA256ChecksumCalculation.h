#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		/**
		 * \brief Checksum calculator that uses the SHA256 algorithm to calculate the checksum of a given file
		 */
		class SHA256ChecksumCalculation : public ChecksumCalculationBase
		{
		public:
			/**
			 * \brief Calculates the checksum of the given file by using the SHA256 algorithm
			 * \param path - file's path
			 * \return - checksum of file
			 */
			string calculate(istream& input_stream) const override;
		};
	}
}

