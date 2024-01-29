#pragma once
#include "Memento.h"

namespace Checksums
{
	namespace Mementos
	{
		class HashStreamWriterMemento : public Memento
		{
		private:

		public:
			void saveState() override;
			void restoreState() override;
		};
	}
}


