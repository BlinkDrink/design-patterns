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

		HashStreamWriter::HashStreamWriter(ostream& output_stream, unique_ptr<ChecksumCalculationBase> calculator) : m_outputStream(output_stream), m_calculator(std::move(calculator))
		{
		}

		void HashStreamWriter::visit(RegularFile& file)
		{
			notifyObservers(file.getPath());
			m_outputStream << m_calculator->calculate(file.getPath()) << endl;
		}

		void HashStreamWriter::visit(Directory& directory)
		{
			// Does nothing to directories, because only the regular files inside them have checksum
		}
	}
}