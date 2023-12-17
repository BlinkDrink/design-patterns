#include "HelpLabel.h"

namespace Problem2
{
	namespace Labels
	{
		string HelpLabel::getText() const
		{
			return m_text;
		}

		string HelpLabel::getHelpText() const
		{
			return m_help_text;
		}

		bool HelpLabel::operator==(const Label& other) const
		{
			const HelpLabel* cast = dynamic_cast<const HelpLabel*>(&other);
			if (!cast)
				return false;

			return m_text == cast->m_text && m_help_text == cast->m_help_text;
		}
	}
}

