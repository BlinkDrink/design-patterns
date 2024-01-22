#pragma once
#include "FileTreeElement.h"

namespace Checksums
{
	namespace TreeElements
	{
		class RegularFile : public FileTreeElement
		{
		private:
			size_t m_file_size; // represents the file size in bytes

		public:
			RegularFile(string path, size_t size);
			void add(unique_ptr<FileTreeElement> child) override;
			string getPath() const override;
			size_t getSize() const override;
		};

	}
}
