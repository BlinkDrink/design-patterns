#include "RichLabel.h"

namespace Problem2
{
	namespace Labels
	{
		RichLabel::RichLabel(const string& value, unsigned short font_size, const string& font_name, const string& text_color) : m_font_size(font_size), m_value(value), m_font_name(font_name), m_text_color(text_color)
		{
		}

		string RichLabel::getText() const
		{
			return m_value;
		}

		bool RichLabel::operator==(const Label& other)
		{
			const RichLabel* cast = dynamic_cast<const RichLabel*>(&other);
			if (!cast)
				return false;

			return m_value == cast->m_value
				&& m_font_size == cast->m_font_size
				&& m_font_name == cast->m_font_name
				&& m_text_color == cast->m_text_color;
		}
	}
}
