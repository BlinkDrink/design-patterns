#pragma once
#include <string>

using std::string;

class Label
{
public:
	virtual string getText() const = 0;
	virtual ~Label() = default;
};
