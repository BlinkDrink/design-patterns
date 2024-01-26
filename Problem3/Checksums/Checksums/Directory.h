#pragma once
#include <vector>

#include "FileTreeElement.h"

namespace Checksums
{
	namespace TreeElements
	{
		using std::vector;

		class Directory : public FileTreeElement
		{
		private:
			vector<unique_ptr<FileTreeElement>> m_children;
			uintmax_t m_size;

		public:
			Directory(string path);
			void add(unique_ptr<FileTreeElement> child) override;
			string getPath() const override;
			uintmax_t getSize() const override;
			string toString() const override;
			void accept(VisitorBase& visitor) override;
		};
	}
}