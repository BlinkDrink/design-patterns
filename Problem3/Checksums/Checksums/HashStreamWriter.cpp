#include "HashStreamWriter.h"

#include <iostream>
#include <thread>

#include "FileMessage.h"

namespace Checksums
{
	namespace TreeElements
	{
		class RegularFile;
	}

	namespace Visitors
	{
		using std::endl;
		using std::make_unique;

		HashStreamWriter::HashStreamWriter(ostream& output_stream, unique_ptr<ChecksumCalculationBase> calculator) : m_outputStream(output_stream), m_calculator(std::move(calculator))
		{
		}

		void HashStreamWriter::visit(RegularFile& file)
		{
			notifyObservers(make_unique<Messages::FileMessage>(file.getPath()));
			m_outputStream << m_calculator->calculate(file.getPath()) << endl;
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
	}
}
