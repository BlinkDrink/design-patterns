#include <filesystem>

#define INTGUID
#include <shobjidl_core.h>
#pragma comment(lib, "shell32.lib")

#include "FollowLinksBuilder.h"
#include "RegularFile.h"


namespace Checksums
{
	namespace Builders
	{
		namespace fs = std::filesystem;
		using std::make_unique;
		using TreeElements::RegularFile;

		bool FollowLinksBuilder::isVisited(const string& path) const
		{
			for (size_t i = 0; i < m_visited.size(); ++i)
			{
				if (m_visited[i] == path)
					return true;
			}

			return false;
		}

		bool FollowLinksBuilder::isSymbolicLink(const string& path)
		{
			const fs::file_status status = fs::symlink_status(path);
			return is_symlink(status);
		}

		bool FollowLinksBuilder::isShortcut(const string& path)
		{
			const fs::path extension = std::filesystem::path(path).extension();
			return extension == ".lnk";
		}

		string FollowLinksBuilder::getTargetPath(const string& path)
		{
			if (isSymbolicLink(path))
			{
				return fs::read_symlink(path).string();
			}

			if (isShortcut(path))
			{
				IShellLink* shell = nullptr;
				CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_IShellLinkW, reinterpret_cast<void**>(&shell));

				IPersistFile* file = nullptr;
				shell->QueryInterface(IID_IPersistFile, reinterpret_cast<void**>(&file));

				file->Load(std::wstring(path.begin(), path.end()).c_str(), STGM_READ);

				char target[MAX_PATH];
				WCHAR wtarget[MAX_PATH];
				MultiByteToWideChar(CP_ACP, 0, target, -1, wtarget, MAX_PATH);
				shell->GetPath(wtarget, MAX_PATH, nullptr, SLGP_RAWPATH);


				file->Release();
				shell->Release();

				return target;
			}

			return path;
		}

		void FollowLinksBuilder::build(const string& path, Directory* parent)
		{
			if (!isVisited(path))
			{
				m_visited.push_back(path);

				if (fs::is_regular_file(path))
				{
					unique_ptr<RegularFile> file = make_unique<RegularFile>(path, fs::file_size(path));

					if (m_root == nullptr)
					{
						m_root = std::move(file);
					}
					else
					{
						parent->add(std::move(file));
					}

					if (isSymbolicLink(path) || isShortcut(path))
					{
						const string target = getTargetPath(path);
						build(target, parent);
					}
				}
				else if (fs::is_directory(path))
				{
					unique_ptr<Directory> dir = make_unique<Directory>(path);
					Directory* current = dir.get();

					if (m_root == nullptr)
					{
						m_root = std::move(dir);
					}
					else
					{
						parent->add(std::move(dir));
					}

					for (const fs::directory_entry& entry : fs::directory_iterator(path))
					{
						build(entry.path().string(), current);
					}
				}
			}
		}

		unique_ptr<FileTreeElement> FollowLinksBuilder::getResult()
		{
			return std::move(m_root);
		}
	}
}
