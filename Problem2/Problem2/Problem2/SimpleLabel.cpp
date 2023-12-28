#include "SimpleLabel.h"

namespace Problem2
{
	namespace Labels
	{
		SimpleLabel::SimpleLabel(const string& value) : m_text(value)
		{
		}

		string SimpleLabel::getText() const
		{
			return m_text;
		}

		bool SimpleLabel::operator==(const Label& other) const
		{
			if (this == &other)
				return true;

			const SimpleLabel* cast = dynamic_cast<const SimpleLabel*>(&other);
			if (!cast)
				return false;

			return m_text == cast->m_text;
		}
	}
}
