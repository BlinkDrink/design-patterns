#include "SHA2ChecksumCalculation.h"

#include <iomanip>
#include <openssl/sha.h>
#include <sstream>

namespace Checksums
{
	namespace ChecksumCalculations
	{
		string SHA2ChecksumCalculation::calculate(istream& input) const
		{
			SHA256_CTX sha256Context;
			SHA256_Init(&sha256Context);

			char buffer[1024];
			while (input.good()) {
				input.read(buffer, sizeof(buffer));
				SHA256_Update(&sha256Context, buffer, input.gcount());
			}

			unsigned char result[SHA256_DIGEST_LENGTH];
			SHA256_Final(result, &sha256Context);

			// Convert the hash to a hex string
			std::stringstream sha256Hash;
			for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
				sha256Hash << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(result[i]);
			}

			return sha256Hash.str();
		}
	}
}