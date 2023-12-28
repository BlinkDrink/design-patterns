#include "RichLabel.h"

namespace Problem2
{
	namespace Labels
	{
		RichLabel::RichLabel(string value, string font_name, string text_color, unsigned short font_size) : m_text(std::move(value)), m_font_name(std::move(font_name)), m_text_color(std::move(text_color)), m_font_size(font_size)
		{
		}

		string RichLabel::getText() const
		{
			return m_text;
		}

		bool RichLabel::operator==(const Label& other) const
		{
			if (this == &other)
				return true;

			const RichLabel* cast = dynamic_cast<const RichLabel*>(&other);
			if (!cast)
				return false;

			return m_text == cast->m_text
				&& m_font_size == cast->m_font_size
				&& m_font_name == cast->m_font_name
				&& m_text_color == cast->m_text_color;
		}
	}
}
