#include "SimpleLabel.h"

namespace Problem2
{
	namespace Labels
	{
		SimpleLabel::SimpleLabel(const string& value) : value(value)
		{
		}

		string SimpleLabel::getText() const
		{
			return value;
		}
	}
}
