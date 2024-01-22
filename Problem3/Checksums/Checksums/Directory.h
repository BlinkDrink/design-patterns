#pragma once
#include "FileTreeElement.h"

namespace Checksums
{
	namespace TreeElements
	{
		class Directory : public FileTreeElement
		{
		private:
			size_t m_size;
		public:
			Directory(string path, size_t size);
			void add(unique_ptr<FileTreeElement> child) override;
			string getPath() const override;
			size_t getSize() const override;
		};
	}
}


