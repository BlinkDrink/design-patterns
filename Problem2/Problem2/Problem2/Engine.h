#pragma once

namespace Problem2
{
	namespace Engines
	{
		class Engine
		{
		private:
			Engine() = default;

		public:
			static Engine& getInstance();

			Engine(const Engine& other) = delete;
			Engine& operator=(const Engine& other) = delete;
			Engine(Engine&& other) = delete;
			Engine& operator=(Engine&& other) = delete;

			void exe();
		};
	}
}
