#include "FileTreeElement.h"

namespace Checksums
{
	namespace TreeElements
	{
		FileTreeElement::FileTreeElement(string path) : m_path(std::move(path))
		{
		}
	}
}
