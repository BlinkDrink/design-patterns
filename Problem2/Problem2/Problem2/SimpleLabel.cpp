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

		bool SimpleLabel::operator==(const Label& other) const
		{
			const SimpleLabel* cast = dynamic_cast<const SimpleLabel*>(&other);
			if (!cast)
				return false;

			return m_value == cast->m_value;
		}
	}
}
