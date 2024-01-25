#pragma once
#include <memory>
#include <string>

#include "FileTreeElement.h"

namespace Checksums
{
	using std::string;
	using std::unique_ptr;
	using TreeElements::Directory;
	using TreeElements::FileTreeElement;

	namespace Builders
	{

		/**
		 * \brief Base class for the builders that will construct the in memory file tree representation
		 */
		class BuilderBase
		{
		protected:
			unique_ptr<FileTreeElement> m_root = nullptr;

		public:
			virtual void build(const string& path, Directory* parent = nullptr) = 0;
			virtual unique_ptr<FileTreeElement> getResult() = 0;
			virtual ~BuilderBase() = default;
		};
	}
}
