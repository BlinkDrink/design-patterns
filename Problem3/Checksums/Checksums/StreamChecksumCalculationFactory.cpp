#include "StreamChecksumCalculationFactory.h"

#include "MD5ChecksumCalculation.h"
#include "SHA256ChecksumCalculation.h"

namespace Checksums
{
	namespace Factories
	{
		using std::string;
		using ChecksumCalculations::SHA256ChecksumCalculation;
		using ChecksumCalculations::MD5ChecksumCalculation;

		StreamChecksumCalculationFactory::StreamChecksumCalculationFactory(istream& stream) : m_stream(stream)
		{
		}

		StreamChecksumCalculationFactory::StreamChecksumCalculationFactory(ifstream&& fileStream) : m_file(std::move(fileStream)), m_stream(m_file)
		{
		}

		unique_ptr<ChecksumCalculationBase> StreamChecksumCalculationFactory::create_calculator()
		{
			string algorithmType;
			if (!(m_stream >> algorithmType))
				throw std::invalid_argument("Insufficient arguments for algorithm name");

			if (algorithmType == "sha256")
			{
				return std::make_unique<SHA256ChecksumCalculation>();
			}
			else if (algorithmType == "md5")
			{
				return std::make_unique<MD5ChecksumCalculation>();
			}

			throw std::invalid_argument("Invalid algorithm type");
		}
	}
}

