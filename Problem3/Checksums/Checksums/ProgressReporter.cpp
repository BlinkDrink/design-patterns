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
		using std::chrono::seconds;
		using Messages::FileMessage;
		using Messages::BytesMessage;
		using std::chrono::time_point;
		using std::chrono::duration_cast;

		ProgressReporter::ProgressReporter(size_t totalBytes) : m_bytesRead(0), m_totalBytes(0), m_totalBytesToBeRead(totalBytes), m_hasWrittenYet(false)
		{
			m_startTime = steady_clock::now();
		}

		void ProgressReporter::update(unique_ptr<Message> msg)
		{
			if (dynamic_cast<const BytesMessage*>(msg.get()))
			{
				stringstream ss(msg->what());
				size_t currentBytes;
				ss >> currentBytes;
				m_bytesRead += currentBytes;
				m_totalBytes += currentBytes;
			}

			if (dynamic_cast<const FileMessage*>(msg.get()))
			{
				m_currentFile = msg->what();
				m_bytesRead = 0;
			}

			display();
		}

		void ProgressReporter::display() const
		{
			const double currPercentage = (static_cast<double>(m_totalBytes) / m_totalBytesToBeRead) * 100.0;
			const double progressPercentage = currPercentage < 100 ? currPercentage : 100;

			const time_point currentTime = steady_clock::now();
			const long long elapsedTime = duration_cast<seconds>(currentTime - m_startTime).count();

			const double bytesPerSecond = static_cast<double>(m_bytesRead) / elapsedTime;
			const double currRemainingTime = (m_totalBytesToBeRead - m_totalBytes) / bytesPerSecond;
			const double remainingTime = currRemainingTime > 0 ? currRemainingTime : 0;

			string newMessage = "\rProcessing " + m_currentFile + "... " + to_string(m_bytesRead) + " byte(s) read (" + to_string(progressPercentage) + "%) - ETA: " + to_string(remainingTime) + " seconds";

			const size_t previousMessageLength = m_previousMessage.length();
			const size_t newMessageLength = newMessage.length();

			if (newMessageLength < previousMessageLength)
				newMessage += string(previousMessageLength - newMessageLength, ' ');

			cout << newMessage;
			cout << std::flush;
			m_previousMessage = newMessage;
		}
	}
}
