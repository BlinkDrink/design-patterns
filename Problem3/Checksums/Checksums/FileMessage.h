#pragma once
#include "Message.h"

namespace Checksums
{
	namespace Messages
	{
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


