#include "HashStreamWriter.h"

namespace Checksums
{
	namespace TreeElements
	{
		class RegularFile;
	}


	namespace Visitors
	{
		using std::endl;

		HashStreamWriter::HashStreamWriter(ostream& os, unique_ptr<ChecksumCalculationBase> calculator) : m_outputStream(os), m_calculator(std::move(calculator))
		{
		}

		void HashStreamWriter::visit(RegularFile& file)
		{
			m_outputStream << m_calculator->calculate(file.getPath()) << endl;
		}

		void HashStreamWriter::visit(Directory& directory)
		{
			// Does nothing to directories, because only the regular files inside them have checksum
		}
	}
}