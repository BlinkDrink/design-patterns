#pragma once
#include "FileTreeElement.h"

namespace Checksums
{
	namespace TreeElements
	{
		class RegularFile : public FileTreeElement
		{
		private:
			uintmax_t m_file_size; // represents the file size in bytes

		public:
			RegularFile(string path, size_t size);
			void add(unique_ptr<FileTreeElement> child) override;
			string getPath() const override;
			uintmax_t getSize() const override;
			string toString() const override;
		};
	}
}
