#pragma once
#include "TextTransformation .h"

class LeftTrimTransformation : public TextTransformation
{
public:
	string transform(string text) const override;
};

