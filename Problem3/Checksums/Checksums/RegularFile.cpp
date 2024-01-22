#pragma once
#include "RegularFile.h"

namespace Checksums
{
	namespace TreeElements
	{
		RegularFile::RegularFile(string path, size_t size) : FileTreeElement(std::move(path)), m_file_size(size)
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

		size_t RegularFile::getSize() const
		{
			return m_file_size;
		}
	}
}
