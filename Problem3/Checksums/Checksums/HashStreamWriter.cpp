#include "HashStreamWriter.h"

#include <iostream>
#include <thread>

#include "FileMessage.h"
#include "HashStreamWriterMemento.h"
#include "PauseScanner.h"
#include "ProgressReporter.h"
#include "ScannerMessage.h"

namespace Checksums
{
	namespace Visitors
	{
		using std::ifstream;
		using std::make_unique;
		using std::invalid_argument;

		HashStreamWriter::HashStreamWriter(ostream& output_stream, unique_ptr<ChecksumCalculations::ChecksumCalculationBase> calculator) : m_outputStream(output_stream), m_calculator(std::move(calculator))
		{
		}

		void HashStreamWriter::visit(RegularFile& file)
		{
			notifyObservers(make_unique<Messages::FileMessage>(file.getPath()));
			ifstream inputStream(file.getPath());
			if (!inputStream.is_open())
				throw invalid_argument("Error opening " + file.getPath() + " for reading.");

			m_outputStream << m_calculator->calculate(inputStream) << " " << file.getPath() << "\n";
		}

		void HashStreamWriter::addObserver(shared_ptr<ObserverBase>& observer)
		{
			ObservableBase::addObserver(observer);
			m_calculator->addObserver(observer);
		}

		void HashStreamWriter::visit(Directory& directory)
		{
			// Does nothing to directories, because only the regular files inside them have checksum
		}

		unique_ptr<Mementos::HashStreamWriterMemento> HashStreamWriter::createMemento()
		{
			return make_unique<Mementos::HashStreamWriterMemento>(m_outputStream.tellp(), std::move(m_calculator));
		}

		void HashStreamWriter::restoreFromMemento(unique_ptr<Mementos::HashStreamWriterMemento>& memento)
		{
			m_outputStream.seekp(memento->m_streamPosition);
			m_calculator = std::move(memento->m_calculator);
		}

		void HashStreamWriter::update(const ObservableBase& sender, unique_ptr<Messages::Message> msg)
		{
			if (dynamic_cast<const Scanners::PauseScanner*>(&sender))
			{
				if (msg->what() == "pause")
				{
					m_state = createMemento();
				}
				else if (msg->what() == "resume")
				{
					restoreFromMemento(m_state);
				}
			}
		}
	}
}
