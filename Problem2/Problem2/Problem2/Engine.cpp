#include "Engine.h"
#include <iostream>

namespace Problem2
{
	namespace Engines
	{
		using std::cout;
		using std::endl;

		void Engine::menu() const
		{

		}

		Engine& Engine::getInstance()
		{
			static Engine instance;
			return instance;
		}

		void Engine::exe()
		{

		}
	}
}

