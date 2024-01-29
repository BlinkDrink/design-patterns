#pragma once
#include "BuilderBase.h"
#include "HashStreamWriter.h"

namespace Checksums
{
	namespace Engines
	{
		using std::unique_ptr;
		using Builders::BuilderBase;

		class Engine
		{
		private:
			void menu() const;
			unique_ptr<BuilderBase> createBuilder() const;
			std::shared_ptr<Observers::ObserverBase> initializeHashStreamWriter() const;

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

