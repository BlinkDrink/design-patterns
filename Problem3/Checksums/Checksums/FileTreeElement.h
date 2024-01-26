#pragma once
#include <memory>
#include <string>

#include "VisitorBase.h"

namespace Checksums
{
	namespace TreeElements
	{
		using std::string;
		using std::unique_ptr;
		using Visitors::VisitorBase;

		/**
		 * \brief Base class for file tree representation
		 */
		class FileTreeElement
		{
		protected:
			string m_path;
		public:
			FileTreeElement(string path);
			virtual void add(unique_ptr<FileTreeElement> child) = 0;
			virtual string getPath() const = 0;
			virtual size_t getSize() const = 0;
			virtual string toString() const = 0;
			virtual void accept(VisitorBase& visitor) = 0;
			virtual ~FileTreeElement() = default;
		};
	}
}
