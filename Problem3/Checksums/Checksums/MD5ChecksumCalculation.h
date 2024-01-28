#pragma once
#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		using Observers::ObserverBase;

		/**
		 * \brief Checksum calculator that uses the MD5 algorithm to calculate the checksum of a given file
		 */
		class MD5ChecksumCalculation : public ChecksumCalculationBase
		{
		public:
			/**
			 * \brief Calculates the checksum of the given file by using the MD5 algorithm
			 * \param path - file's path
			 * \return - checksum of file
			 */
			string calculate(const string& path) const override;
		};
	}
}

