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
	}
}
