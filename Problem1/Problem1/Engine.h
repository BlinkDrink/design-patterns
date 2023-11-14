#pragma once
#include <memory>
#include <vector>
#include "Figure.h"

namespace Problem1
{
	using Figures::Figure;
	using std::vector;

	namespace Engine
	{
		class Engine
		{
		private:
			Engine();

			/**
			 * \brief Prints the user interface for working with this program
			 */
			void menu() const;

			/**
			 * \brief Saves collection of figures to a file, each on a new row
			 * \param filename - name of file where the figures will be written
			 * \param figures - collection of figures
			 */
			void saveFiguresToFile(const string& filename, const std::vector<unique_ptr<Figure>>& figures) const;

			/**
			 * \brief Prints the figures to std::out using their respective toString method
			 * \param figures - collection of figures
			 */
			void printFigures(const vector<unique_ptr<Figure>>& figures) const;

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
