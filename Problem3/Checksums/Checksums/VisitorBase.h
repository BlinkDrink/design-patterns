#pragma once
#include "Directory.h"
#include "RegularFile.h"

namespace Checksums
{
	namespace Visitors
	{
		using TreeElements::Directory;
		using TreeElements::RegularFile;

		class VisitorBase
		{
		public:
			virtual void visit(RegularFile& file) = 0;
			virtual void visit(Directory& directory) = 0;
			virtual ~VisitorBase() = default;
		};
	}
}
