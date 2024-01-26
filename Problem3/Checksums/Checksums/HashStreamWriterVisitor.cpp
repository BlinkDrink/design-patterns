#include "HashStreamWriterVisitor.h"

namespace Checksums
{
	namespace TreeElements
	{
		class RegularFile;
	}

	namespace Visitors
	{
		HashStreamWriterVisitor::HashStreamWriterVisitor(ostream& os, unique_ptr<ChecksumCalculationBase> calculator) : m_outputStream(os), m_calculator(std::move(calculator))
		{
		}

		void HashStreamWriterVisitor::visit(RegularFile& file)
		{
			m_outputStream << file.getPath() << m_calculator->calculate(file.getPath());
		}

		void HashStreamWriterVisitor::visit(Directory& directory)
		{
		}
	}
}