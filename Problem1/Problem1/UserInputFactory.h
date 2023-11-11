#pragma once
#include "InputFactory.h"

class UserInputFactory : public InputFactory
{
public:
	/**
	 * \brief Method used for creating a FigureFactory based on the input type by the user
	 * \param inputType - the type of factory to create 
	 * \return - dynamically created factory which will serve as a creator of objects
	 */
	unique_ptr<FigureFactory> create_figure_factory(const string& inputType) const override;
};