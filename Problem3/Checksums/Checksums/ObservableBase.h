#pragma once

#include <memory>
#include <vector>

#include "ObserverBase.h"

namespace Checksums
{
	namespace Observers
	{
		using std::vector;
		using std::unique_ptr;
		using std::shared_ptr;

		/**
		 * \brief Base class for all observables that can notify their observers
		 */
		class ObservableBase
		{
		private:
			vector<shared_ptr<ObserverBase>> m_observers;

		public:
			virtual void addObserver(shared_ptr<ObserverBase>& observer);
			void notifyObservers(shared_ptr<Message> msg) const;
			virtual ~ObservableBase() = default;
		};
	}
}
