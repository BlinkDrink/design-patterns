#pragma once
#include "ObservableBase.h"


namespace Checksums
{
	namespace Scanners
	{
		class PauseScanner : public Observers::ObservableBase
		{
		private:
			bool m_isPaused;
		public:
			PauseScanner();

			void start();
			void pause();
			void resume();
			void stop();
		};
	}
}
