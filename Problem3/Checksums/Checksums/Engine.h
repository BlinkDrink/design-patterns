#pragma once
#include "BuilderBase.h"
#include "HashStreamWriter.h"
#include "ProgressReporter.h"

namespace Checksums
{
	namespace Engines
	{
		using std::string;
		using std::unique_ptr;
		using std::shared_ptr;
		using Visitors::VisitorBase;
		using Builders::BuilderBase;
		using Observers::ProgressReporter;
		using Observers::ObserverBase;

		class Engine
		{
		private:
			void menu() const;
			unique_ptr<BuilderBase> createBuilder() const;
			shared_ptr<ObserverBase> initializeHashStreamWriter() const;
			string pathToFileInput() const;

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

