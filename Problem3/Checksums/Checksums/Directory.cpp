#include "Directory.h"

namespace Checksums
{
	namespace TreeElements
	{
		using std::to_string;

		Directory::Directory(string path) : FileTreeElement(std::move(path)), m_size(0)
		{
		}

		void Directory::add(unique_ptr<FileTreeElement> child)
		{
			m_children.push_back(std::move(child));
		}

		string Directory::getPath() const
		{
			return m_path;
		}

		size_t Directory::getSize() const
		{
			size_t totalSize = 0;
			for (const unique_ptr<FileTreeElement>& child : m_children)
				totalSize += child->getSize();

			return totalSize;
		}

		string Directory::toString() const
		{
			return getPath() + " " + std::to_string(getSize());
		}
	}
}