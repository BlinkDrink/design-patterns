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

		class FollowLinksBuilder : public BuilderBase
		{
		private:
			vector<string> m_visited;

			static bool isSymbolicLink(const string& path);
			static bool isShortcut(const string& path);
			string getTargetPath(const string& path);
		public:
			void build(const string& path, Directory* parent = nullptr) override;
			unique_ptr<FileTreeElement> getResult() override;
		};
	}
}


