#pragma once
#include "FileTreeElement.h"

namespace Checksums
{
	namespace TreeElements
	{

		/**
		 * \brief Represents a Regular File node (leaf) in the File Tree representation
		 */
		class RegularFile : public FileTreeElement
		{
		private:
			uintmax_t m_file_size; // represents the file size in bytes

		public:
			RegularFile(string path, size_t size);

			/**
			 * \brief Does nothing for RegularFiles (choosing transparency over safety)
			 * \param child
			 */
			void add(unique_ptr<FileTreeElement> child) override;

			/**
			 * \brief Getter
			 * \return - the relative path to the current file
			 */
			string getPath() const override;

			/**
			 * \brief Getter
			 * \return - the total size of the current file
			 */
			uintmax_t getSize() const override;

			/**
			 * \brief Entry point for every visitor object.
			 * \param visitor - the visitor whose logic will be applied on the current node
			 */
			void accept(VisitorBase& visitor) override;
		};
	}
}
