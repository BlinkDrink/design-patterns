#pragma once
#include <openssl/md5.h>
#include <openssl/evp.h>

#include "ChecksumCalculationBase.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		using std::istream;
		using std::streampos;
		using Observers::ObserverBase;

		/**
		 * \brief Checksum calculator that uses the MD5 algorithm to calculate the checksum of a given file
		 */
		class MD5ChecksumCalculation : public ChecksumCalculationBase
		{
		public:
			/**
			 * \brief Calculates the checksum of the given file by using the MD5 algorithm
			 * \param input_stream - the stream from which information will be read
			 * \return - checksum of file
			 */
			string calculate(istream& inputStream) const override;
		};
	}
}

