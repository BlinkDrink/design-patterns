#pragma once
#include "Label.h"
class SimpleLabel : public Label
{
private:
	string value;

public:
	SimpleLabel(const string& value);

	string getText() const override;
};

