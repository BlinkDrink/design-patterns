#include "SimpleLabel.h"

SimpleLabel::SimpleLabel(const string& value) : value(value)
{
}

string SimpleLabel::getText() const
{
	return value;
}
