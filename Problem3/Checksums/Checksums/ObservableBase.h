#pragma once

#include <memory>
#include <vector>

#include "ObserverBase.h"

namespace Checksums
{
	namespace Observers
	{
		using std::vector;
		using std::shared_ptr;

		class ObservableBase
		{
		private:
			vector<shared_ptr<ObserverBase>> m_observers;

		public:
			void addObserver(shared_ptr<ObserverBase> observer);
			void notifyObservers(const string& fileName) const;
		};
	}
}
