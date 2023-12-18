#include "HelpLabel.h"

namespace Problem2
{
	namespace Labels
	{
		HelpLabel::HelpLabel(unique_ptr<Label>& implementation, const string& help_text) : m_imp(std::move(implementation)), m_help_text(help_text)
		{
		}

		string HelpLabel::getText() const
		{
			return m_imp->getText();
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

			return m_imp == cast->m_imp && m_help_text == cast->m_help_text;
		}
	}
}

