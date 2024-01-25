#include "FollowLinksBuilder.h"

namespace Checksums
{
	namespace Builders
	{
		void FollowLinksBuilder::build(const string& path, Directory* parent)
		{
		}

		unique_ptr<FileTreeElement> FollowLinksBuilder::getResult()
		{
			return std::move(m_root);
		}
	}
}