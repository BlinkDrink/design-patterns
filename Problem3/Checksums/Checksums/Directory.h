#pragma once
#include "FileTreeElement.h"
#include <vector>

namespace Checksums
{
	namespace TreeElements
	{
		using std::vector;


		/**
		 * \brief Composite structure for file hierarchy representation
		 */
		class Directory : public FileTreeElement
		{
		private:
			vector<unique_ptr<FileTreeElement>> m_children;
			uintmax_t m_size;

		public:
			Directory(string path);

			/**
			 * \brief Adds the given FileTreeElement to the children of the current directory. Adds the file's
			 * total size to the directory's size
			 * \param child - element to be added
			 */
			void add(unique_ptr<FileTreeElement> child) override;

			/**
			 * \brief Getter
			 * \return - the relative path of the current directory
			 */
			string getPath() const override;

			/**
			 * \brief Getter
			 * \return - the total size of the directory in bytes
			 */
			uintmax_t getSize() const override;

			/**
			 * \brief Entry point for every visitor object. Traverses the tree whilst applying the visitors logic on each node
			 * \param visitor - the visitor whose logic will be applied on each node
			 */
			void accept(VisitorBase& visitor) override;
		};
	}
}