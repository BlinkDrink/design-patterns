#include "ObservableBase.h"

namespace Checksums
{
	namespace Observers
	{
		void ObservableBase::addObserver(shared_ptr<ObserverBase>& observer)
		{
			m_observers.push_back(observer);
		}

		void ObservableBase::notifyObservers(unique_ptr<Message> msg) const
		{
			for (const shared_ptr<ObserverBase>& observer : m_observers)
			{
				observer->update(*this, std::move(msg));
			}
		}
	}
}