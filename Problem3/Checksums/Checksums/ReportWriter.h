#pragma once
#include <ostream>
#include <vector>
#include "VisitorBase.h"

namespace Checksums
{
	namespace Visitors
	{
		using std::vector;
		using std::ostream;

		/**
		 * \brief Visitor used to traverse the target file tree and output all files in the tree and their sizes
		 * before the actual scan has begun
		 */
		class ReportWriter : public VisitorBase
		{
		private:
			ostream& m_outputStream;

		public:
			ReportWriter(ostream& outputStream);
			void visit(RegularFile& file) override;
			void visit(Directory& directory) override;
		};
	}
}


