#include "SimpleLabel.h"

namespace Problem2
{
	namespace Labels
	{
		SimpleLabel::SimpleLabel(const string& value) : _value(value)
		{
		}

		string SimpleLabel::getText() const
		{
			return _value;
		}
	}
}
