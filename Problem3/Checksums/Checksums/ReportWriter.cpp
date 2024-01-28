#include "ReportWriter.h"

#include "RegularFile.h"

namespace Checksums
{
	namespace Visitors
	{
		using std::endl;

		ReportWriter::ReportWriter(ostream& outputStream) : m_outputStream(outputStream)
		{
		}

		void ReportWriter::visit(RegularFile& file)
		{
			m_outputStream << file.getPath() << " - " << file.getSize() << " byte(s)" << endl;
		}

		void ReportWriter::visit(Directory& directory)
		{
			// does nothing to directories, as they are a collection of regular files
		}
	}
}
