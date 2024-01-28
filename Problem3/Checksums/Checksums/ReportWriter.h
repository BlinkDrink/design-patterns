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


