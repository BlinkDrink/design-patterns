#include "RichLabel.h"

namespace Problem2
{
	namespace Labels
	{
		RichLabel::RichLabel(const string& value, unsigned short font_size, const string& font_name, const string& text_color) : _font_size(font_size), _value(value), _font_name(font_name), _text_color(text_color)
		{
		}

		string RichLabel::getText() const
		{
			return _value;
		}
	}
}
