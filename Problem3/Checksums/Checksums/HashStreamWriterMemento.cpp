#include "HashStreamWriterMemento.h"

namespace Checksums
{
	namespace Mementos
	{
		HashStreamWriterMemento::HashStreamWriterMemento(streampos streamPosition,
			std::unique_ptr<ChecksumCalculations::ChecksumCalculationBase> calculator) : m_streamPosition(streamPosition), m_calculator(std::move(calculator))
		{
		}
	}
}
