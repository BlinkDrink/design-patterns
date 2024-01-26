#pragma once
#include "BuilderBase.h"

namespace Checksums
{
	namespace Builders
	{
		class NoFollowLinksBuilder : public BuilderBase
		{
		public:

			void build(const string& path, TreeElements::Directory* parent = nullptr) override;
			unique_ptr<FileTreeElement> getResult() override;
		};
	}
}

