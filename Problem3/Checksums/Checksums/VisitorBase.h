#pragma once

namespace Checksums
{
	namespace TreeElements
	{
		class RegularFile;
		class Directory;
	}

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
