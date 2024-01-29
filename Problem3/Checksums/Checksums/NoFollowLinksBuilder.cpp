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
				unique_ptr<RegularFile> file = std::make_unique<RegularFile>(fs::relative(fs::absolute(path)).string(), fs::file_size(path));

				if (m_root == nullptr)
				{
					m_root = std::move(file);
				}
				else if (parent)
				{
					parent->add(std::move(file));
				}
			}
			else if (fs::is_directory(path))
			{
				unique_ptr<Directory> dir = make_unique<Directory>(fs::relative(fs::absolute(path)).string());
				Directory* current = dir.get();

				if (m_root == nullptr)
				{
					m_root = std::move(dir);
				}

				for (const fs::directory_entry& entry : fs::directory_iterator(path))
				{
					build(entry.path().string(), current);
				}

				if (m_root && dir)
					parent->add(std::move(dir));
			}
		}

		unique_ptr<FileTreeElement> NoFollowLinksBuilder::getResult()
		{
			return std::move(m_root);
		}
	}
}
