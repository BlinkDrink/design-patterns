#include "RegularFile.h"
#include "VisitorBase.h"

namespace Checksums
{
	namespace TreeElements
	{
		using std::to_string;

		RegularFile::RegularFile(string path, uintmax_t size) : FileTreeElement(std::move(path)), m_file_size(size)
		{
		}

		void RegularFile::add(unique_ptr<FileTreeElement> child)
		{
			// does nothing unless it's a composite (directory)
		}

		string RegularFile::getPath() const
		{
			return m_path;
		}

		uintmax_t RegularFile::getSize() const
		{
			return m_file_size;
		}

		void RegularFile::accept(VisitorBase& visitor)
		{
			visitor.visit(*this);
		}
	}
}
