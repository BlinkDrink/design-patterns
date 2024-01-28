#include "Directory.h"

#include <iostream>

#include "VisitorBase.h"

namespace Checksums
{
	namespace TreeElements
	{
		using std::to_string;
		using std::endl;

		Directory::Directory(string path) : FileTreeElement(std::move(path)), m_size(0)
		{
		}

		void Directory::add(unique_ptr<FileTreeElement> child)
		{
			m_size += child->getSize();
			m_children.push_back(std::move(child));
		}

		string Directory::getPath() const
		{
			return m_path;
		}

		uintmax_t Directory::getSize() const
		{
			return m_size;
		}

		string Directory::toString() const
		{
			string res;
			res += getPath() + " " + std::to_string(getSize());
			for (const unique_ptr<FileTreeElement>& child : m_children)
				res += "\n" + child->toString();

			return res;
		}

		void Directory::accept(VisitorBase& visitor)
		{
			visitor.visit(*this);
			for (const unique_ptr<FileTreeElement>& child : m_children)
			{
				child->accept(visitor);
			}
		}
	}
}