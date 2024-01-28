#pragma once
#include <unordered_map>

#include "BuilderBase.h"
#include "Directory.h"

namespace Checksums
{
	namespace Builders
	{
		using std::vector;
		using std::unique_ptr;

		/**
		 * \brief FileTree builder that follows symbolic links(on UNIX based machines) or shortcuts(on windows based machines)
		 */
		class FollowLinksBuilder : public BuilderBase
		{
		private:
			/**
			 * \brief Visited nodes. Used in cycle detection
			 */
			vector<string> m_visited;

			/**
			 * \brief Helper method that checks whether a file is a symbolic link or not
			 * \param path - the path to the file that will be checked
			 * \return - true if it is a symbolic link, false otherwise
			 */
			static bool isSymbolicLink(const string& path);

			/**
			 * \brief Helper method that checks whether a file is a shortcut or not
			 * \param path - the path to the file that will be checked
			 * \return - true if it is a shortcut, false otherwise
			 */
			static bool isShortcut(const string& path);

			/**
			 * \brief If the given path matches a Symbolic link or Shortcut, then the target of that link/shortcut is returned
			 * in the form of new string (the path to the object that is pointed to by the link/shortcut)
			 * \param path - path to the given link/shortcut
			 * \return - the path to the pointed file
			 */
			static string getTargetPath(const string& path);
		public:
			/**
			 * \brief General method used to begin File Tree building (recursively).
			 * \param path - path to the root file/directory
			 * \param parent - the directory containing the file that leads from path
			 */
			void build(const string& path, Directory* parent = nullptr) override;

			/**
			 * \brief Returns the root of the in-memory representation of the tree
			 * \return - the root of the newly built tree
			 */
			unique_ptr<FileTreeElement> getResult() override;
		};
	}
}


