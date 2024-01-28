#pragma once
#include "Message.h"

namespace Checksums
{
	namespace Messages
	{

		/**
		 * \brief Represents a simple message that carries information about what file is being processed currently
		 */
		class FileMessage : public Message
		{
		private:
			string m_fileName;
		public:
			FileMessage(const string& fileName);
			string what() const override;
		};
	}
}


