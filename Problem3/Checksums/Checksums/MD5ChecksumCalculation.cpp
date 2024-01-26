#include "MD5ChecksumCalculation.h"

#include <iomanip>
#include <sstream>
#include <openssl/md5.h>

namespace Checksums
{
	namespace ChecksumCalculations
	{
		using std::stringstream;
		using std::hex;
		using std::setw;
		using std::setfill;

		string MD5ChecksumCalculation::calculate(istream& input) const
		{
			MD5_CTX md5Context;
			MD5_Init(&md5Context);

			char buffer[1024];
			while (input.good())
			{
				input.read(buffer, sizeof(buffer));
				MD5_Update(&md5Context, buffer, input.gcount());
			}

			unsigned char result[MD5_DIGEST_LENGTH];
			MD5_Final(result, &md5Context);

			stringstream md5Hash;
			for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
			{
				md5Hash << hex << setw(2) << setfill('0') << static_cast<int>(result[i]);
			}

			return md5Hash.str();
		}
	}
}
