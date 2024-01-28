#include "ProgressReporter.h"

#include <iostream>

namespace Checksums
{
	namespace Observers
	{
		using std::cout;

		void ProgressReporter::update(const string& fileName)
		{
			cout << "Processing " << fileName << "...";
		}
	}
}
