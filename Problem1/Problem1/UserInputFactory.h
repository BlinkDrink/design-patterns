#pragma once
#include "Figure.h"
#include "StreamFigureFactory.h"

namespace Problem1
{
	namespace Factories
	{
		using Factories::FigureFactory;

		/**
		 * \brief Singleton
		 */
		class UserInputFactory
		{
		private:
			UserInputFactory() = default;
		public:
			/**
			 * \brief Method used for creating a FigureFactory based on the input type by the user
			 * \param input_type - the type of factory to create
			 * \return - dynamically created factory which will serve as a creator of objects
			 */
			unique_ptr<FigureFactory> create_figure_factory(const string& input_type) const;

			static UserInputFactory& getInstance();

			UserInputFactory(const UserInputFactory& other) = delete;
			UserInputFactory& operator=(const UserInputFactory& other) = delete;
			UserInputFactory(UserInputFactory&& other) = delete;
			UserInputFactory& operator=(UserInputFactory&& other) = delete;
		};
	}
}
