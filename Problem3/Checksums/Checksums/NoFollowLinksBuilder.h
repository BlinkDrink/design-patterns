#pragma once
#include "BuilderBase.h"

namespace Checksums
{
	namespace Builders
	{
		class NoFollowLinksBuilder : public BuilderBase
		{
		public:
			/**
			 * \brief General method used to begin File Tree building (recursively).
			 * \param path - path to the root file/directory
			 * \param parent - the directory containing the file that leads from path
			 */
			void build(const string& path, Directory* parent = nullptr) override;

			/**
			 * \brief Returns the root of the in-memory representation of the tree
			 * \return - the root of the newly built tree
			 */
			unique_ptr<FileTreeElement> getResult() override;
		};
	}
}

