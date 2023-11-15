#pragma once
#include <memory>
#include <vector>
#include "Figure.h"

namespace Problem1
{
	using Figures::Figure;
	using std::vector;
	using std::ostream;

	namespace Engine
	{
		class Engine
		{
		private:
			Engine() = default;

			/**
			 * \brief Prints the user interface for working with this program
			 */
			void menu() const;

			/**
			 * \brief Saves collection of figures to a file, each on a new row
			 * \param filename - name of file where the figures will be written
			 * \param figures - collection of figures
			 * \param target - the stream to which the figures will be output
			 */
			void outputFiguresTo(const std::vector<unique_ptr<Figure>>& figures, ostream& target) const;

			/**
			 * \brief Prompts the user for input - the id of a figure
			 * then duplicates it and adds it to the collection of figures
			 * \param figures - collection of figures
			 */
			void duplicateAndAddFigure(vector<unique_ptr<Figure>>& figures) const;

			/**
			 * \brief Prompts the user for input - the id of a figure
			 * then removes it from the collection of figures
			 * \param figures
			 */
			void removeFigure(vector<unique_ptr<Figure>>& figures) const;

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
