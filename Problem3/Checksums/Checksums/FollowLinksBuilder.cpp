#include <filesystem>

#define INTGUID
#include <shobjidl_core.h>
#include <windows.h>
#include <shobjidl.h>
#include <shlguid.h>
#pragma comment(lib, "shell32.lib")

#include "FollowLinksBuilder.h"
#include "RegularFile.h"

namespace Checksums
{
	namespace Builders
	{
		namespace fs = std::filesystem;
		using std::find;
		using std::make_unique;
		using TreeElements::RegularFile;

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
				CoInitialize(nullptr);
				IShellLink* pShellLink;
				HRESULT hr = CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&pShellLink);

				if (SUCCEEDED(hr))
				{
					IPersistFile* pPersistFile;
					hr = pShellLink->QueryInterface(IID_IPersistFile, (LPVOID*)&pPersistFile);

					if (SUCCEEDED(hr))
					{
						WCHAR wsz[MAX_PATH];
						MultiByteToWideChar(CP_ACP, 0, path.c_str(), -1, wsz, MAX_PATH);
						hr = pPersistFile->Load(wsz, STGM_READ);

						if (SUCCEEDED(hr))
						{
							// Get the target path
							WCHAR targetPath[MAX_PATH];
							hr = pShellLink->GetPath(targetPath, MAX_PATH, nullptr, 0);

							if (SUCCEEDED(hr))
							{
								// Convert the target path to a std::string
								char targetPathStr[MAX_PATH];
								WideCharToMultiByte(CP_ACP, 0, targetPath, -1, targetPathStr, MAX_PATH, nullptr, nullptr);
								std::string result(targetPathStr);
								return result;
							}
						}

						pPersistFile->Release();
					}

					pShellLink->Release();
				}

				CoUninitialize();
			}

			return path;
		}

		void FollowLinksBuilder::build(const string& path, Directory* parent)
		{
			if (find(m_visited.begin(), m_visited.end(), path) != m_visited.end())
			{
				return;
			}

			m_visited.push_back(path);

			if (isSymbolicLink(path) || isShortcut(path))
			{
				const string targetPath = getTargetPath(path);
				build(targetPath, parent);
			}
			else if (fs::is_regular_file(path))
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

		unique_ptr<FileTreeElement> FollowLinksBuilder::getResult()
		{
			m_visited.clear();
			return std::move(m_root);
		}
	}
}
