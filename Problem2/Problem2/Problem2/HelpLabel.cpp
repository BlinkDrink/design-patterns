#include "HelpLabel.h"

#include <stdexcept>

namespace Problem2
{
	namespace Labels
	{
		using std::invalid_argument;

		HelpLabel::HelpLabel(unique_ptr<Label> implementation, string help_text) : m_help_text(std::move(help_text))
		{
			if (!implementation)
				throw invalid_argument("Reference to underlying label cannot be null");

			m_imp = std::move(implementation);
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
			if (this == &other)
				return true;

			const HelpLabel* cast = dynamic_cast<const HelpLabel*>(&other);
			if (!cast)
				return false;

			return m_help_text == cast->m_help_text && *m_imp == *cast->m_imp;
		}

		void HelpLabel::setHelpText(string help_text)
		{
			m_help_text = std::move(help_text);
		}
	}
}

