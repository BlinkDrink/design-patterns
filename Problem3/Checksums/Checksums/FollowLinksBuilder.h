#pragma once
#include <unordered_map>

#include "BuilderBase.h"
#include "Directory.h"

namespace Checksums
{
	namespace Builders
	{
		using std::vector;
		using std::unique_ptr;
		using TreeElements::Directory;

		class FollowLinksBuilder : public BuilderBase
		{
		private:
			vector<string> m_visited;

		public:
			void build(const string& path, Directory* parent) override;
			unique_ptr<FileTreeElement> getResult() override;
		};
	}
}


