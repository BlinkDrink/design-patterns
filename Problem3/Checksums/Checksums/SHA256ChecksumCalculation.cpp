#include "SHA256ChecksumCalculation.h"

#include <iomanip>
#include <openssl/sha.h>
#include <sstream>

namespace Checksums
{
	namespace ChecksumCalculations
	{
		using std::stringstream;
		using std::hex;
		using std::setw;
		using std::setfill;

		string SHA256ChecksumCalculation::calculate(const string& path) const
		{
			std::ifstream file(path, std::ios::binary);
			if (!file.is_open())
			{
				throw std::invalid_argument("Error opening file " + path + " for reading");
			}

			SHA256_CTX sha256Context;
			SHA256_Init(&sha256Context);

			while (file.good())
			{
				char buffer[1024];
				file.read(buffer, sizeof(buffer));
				SHA256_Update(&sha256Context, buffer, file.gcount());
			}

			unsigned char result[SHA256_DIGEST_LENGTH];
			SHA256_Final(result, &sha256Context);

			// Convert the hash to a hex string
			stringstream sha256Hash;
			for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
			{
				sha256Hash << hex << setw(2) << setfill('0') << static_cast<int>(result[i]);
			}

			return sha256Hash.str();
		}
	}
}