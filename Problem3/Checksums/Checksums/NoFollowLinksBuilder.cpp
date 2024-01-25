#include<filesystem>

#include "Directory.h"
#include "RegularFile.h"
#include "NoFollowLinksBuilder.h"

namespace fs = std::filesystem;

namespace Checksums
{
	namespace Builders
	{
		using std::make_unique;
		using TreeElements::Directory;
		using TreeElements::RegularFile;

		void NoFollowLinksBuilder::build(const string& path, Directory* parent)
		{
			if (fs::is_regular_file(path))
			{
				unique_ptr<RegularFile> file = std::make_unique<RegularFile>(path, fs::file_size(path));

				if (m_root == nullptr)
				{
					m_root = std::move(file);
				}
				else if (parent)
				{
					parent->add(std::move(file));
				}
			}
			else if (std::filesystem::is_directory(path))
			{
				unique_ptr<Directory> dir = make_unique<Directory>(path);

				if (m_root == nullptr)
				{
					m_root = std::move(dir);
				}
				else
				{
					for (const fs::directory_entry& entry : fs::directory_iterator(path))
					{
						build(entry.path().string(), dir.get());
					}
					m_root->add(std::move(dir));
				}
			}
		}

		unique_ptr<FileTreeElement> NoFollowLinksBuilder::getResult()
		{
			return std::move(m_root);
		}
	}
}
