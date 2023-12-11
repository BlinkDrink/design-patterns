#include "SimpleLabel.h"

namespace Problem2
{
	namespace Labels
	{
		SimpleLabel::SimpleLabel(const string& value) : m_value(value)
		{
		}

		string SimpleLabel::getText() const
		{
			return m_value;
		}
	}
}
