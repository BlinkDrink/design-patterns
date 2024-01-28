#include "ProgressReporter.h"

#include <iostream>

namespace Checksums
{
	namespace Observers
	{
		using std::cout;
		using std::endl;

		void ProgressReporter::update(const string& fileName)
		{
			cout << "Processing " << fileName << "..." << endl;
		}
	}
}
