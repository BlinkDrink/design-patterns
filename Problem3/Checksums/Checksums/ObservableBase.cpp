#include "ObservableBase.h"

namespace Checksums
{
	namespace Observers
	{
		void ObservableBase::addObserver(shared_ptr<ObserverBase> observer)
		{
			m_observers.push_back(observer);
		}

		void ObservableBase::notifyObservers(const string& fileName) const
		{
			for (const shared_ptr<ObserverBase>& observer : m_observers)
			{
				observer->update(fileName);
			}
		}
	}
}