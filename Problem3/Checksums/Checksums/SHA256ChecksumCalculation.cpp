#include "SHA256ChecksumCalculation.h"

#include <iomanip>
#include <openssl/sha.h>
#include <sstream>

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

		string SHA256ChecksumCalculation::calculate(istream& input_stream) const
		{
			SHA256_CTX sha256Context;
			SHA256_Init(&sha256Context);

			while (input_stream.good())
			{
				char buffer[1024];
				input_stream.read(buffer, sizeof(buffer));
				size_t bytesRead = static_cast<size_t>(input_stream.gcount());
				SHA256_Update(&sha256Context, buffer, bytesRead);
				notifyObservers(make_unique<BytesMessage>(bytesRead));
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
