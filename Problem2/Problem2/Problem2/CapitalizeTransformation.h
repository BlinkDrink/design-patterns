#pragma once

#include "TextTransformation .h"

class CapitalizeTransformation : public TextTransformation
{
public:

	/**
	 * \brief Transforms a given string to it's capitalized first letter version
	 * \param text - input whose first letter will be capitalized(if possible)
	 * \return the newly formed string
	 */
	string transform(const string& text) const override;
};

