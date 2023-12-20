#include "HelpLabel.h"

namespace Problem2
{
	namespace Labels
	{
		HelpLabel::HelpLabel(unique_ptr<Label> implementation, string help_text) : m_imp(std::move(implementation)), m_help_text(std::move(help_text))
		{
		}

		string HelpLabel::getText() const
		{
			if (m_imp)
				return m_imp->getText();

			return "";
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

			return m_help_text == cast->m_help_text && *m_imp == *cast->m_imp;
		}
	}
}

