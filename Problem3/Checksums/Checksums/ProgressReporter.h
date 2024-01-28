#pragma once
#include "ObserverBase.h"

namespace Checksums
{
	namespace Observers
	{
		class ProgressReporter : public ObserverBase
		{
		public:
			void update(const string& fileName) override;
		};
	}
}