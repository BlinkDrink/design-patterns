#include "MD5ChecksumCalculation.h"

#include <iomanip>
#include <sstream>
#include <openssl/md5.h>

#include "BytesMessage.h"

namespace Checksums
{
	namespace ChecksumCalculations
	{
		using std::hex;
		using std::setw;
		using std::setfill;
		using std::make_unique;
		using std::stringstream;
		using Messages::BytesMessage;

		string MD5ChecksumCalculation::calculate(const string& path) const
		{
			std::ifstream file(path, std::ios::binary);
			if (!file.is_open())
			{
				throw std::invalid_argument("Error opening file " + path + " for reading.");
			}

			MD5_CTX md5Context;
			MD5_Init(&md5Context);

			while (file.good())
			{
				char buffer[1024];
				file.read(buffer, sizeof(buffer));
				const int bytesRead = static_cast<size_t>(file.gcount());
				MD5_Update(&md5Context, buffer, bytesRead);
				notifyObservers(make_unique<BytesMessage>(bytesRead));
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
