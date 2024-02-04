#pragma once
#include<iostream>
#include "BuilderBase.h"
#include "HashStreamWriter.h"
#include "ProgressReporter.h"
#include "PauseScanner.h"

namespace Checksums
{
	namespace Engines
	{
		using std::string;
		using std::unique_ptr;
		using std::shared_ptr;
		using std::mutex;
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
			unique_ptr<Scanners::PauseScanner> m_pauseScanner;

			shared_ptr<ObserverBase> m_writer;
			shared_ptr<ObserverBase> m_progressReporter;
			shared_ptr<VisitorBase> m_visitor;
			shared_ptr<TreeElements::FileTreeElement> m_tree;

			void initializePauseScanner(unique_ptr<TreeElements::FileTreeElement> tree);

			Engine();

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

