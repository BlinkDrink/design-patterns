#pragma once

namespace Checksums
{
	namespace Mementos
	{
		class Memento
		{
		public:
			virtual void saveState() = 0;
			virtual void restoreState() = 0;
			virtual ~Memento() = default;
		};
	}
}