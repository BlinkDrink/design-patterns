#pragma once
#include <string>

using std::string;

class TextTransformation
{
public:
	virtual string transform(const string& text) const = 0;
	virtual ~TextTransformation() = default;
};
