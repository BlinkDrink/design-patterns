#pragma once
#include "TextTransformation .h"

class LeftTrimTransformation : public TextTransformation
{
public:
	/**
	 * \brief Remove the leading whitespace from a string
	 * \param text - string whose whitespace will be deleted(if any)
	 * \return - the newly transformed string
	 */
	string transform(string text) const override;
};

