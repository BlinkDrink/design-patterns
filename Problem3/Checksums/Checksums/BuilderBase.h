#pragma once
#include <memory>
#include <string>

#include "FileTreeElement.h"

namespace Checksums
{
	namespace Builders
	{
		using std::string;
		using TreeElements::FileTreeElement;

		class BuilderBase
		{
		public:
			virtual void buildFile(const string& path, size_t size) const = 0;
			virtual void buildDirectory(const string& path) const = 0;
			virtual std::shared_ptr<FileTreeElement> getResult() = 0;
			virtual ~BuilderBase() = default;
		};
	}
}
