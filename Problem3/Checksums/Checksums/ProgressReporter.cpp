#include "ProgressReporter.h"

#include <iostream>
#include <sstream>

#include "BytesMessage.h"
#include "FileMessage.h"

namespace Checksums
{
	namespace Observers
	{
		using std::cout;
		using std::endl;
		using std::to_string;
		using std::stringstream;
		using Messages::FileMessage;
		using Messages::BytesMessage;

		void ProgressReporter::update(unique_ptr<Message> msg)
		{
			if (dynamic_cast<const BytesMessage*>(msg.get()))
			{
				stringstream ss(msg->what());
				size_t currentBytes;
				ss >> currentBytes;
				m_bytesRead += currentBytes;
			}

			if (dynamic_cast<const FileMessage*>(msg.get()))
			{
				if (m_hasWrittenYet)
					cout << endl;
				m_currentFile = msg->what();
				m_bytesRead = 0;
			}

			display();
			m_hasWrittenYet = true;
		}

		void ProgressReporter::display() const
		{
			cout << "\rProcessing " + m_currentFile + "... " + to_string(m_bytesRead) + " byte(s) read" << std::flush;
		}
	}
}
