#include "RichLabel.h"

RichLabel::RichLabel(const string& value, unsigned short font_size, const string& font_name, const string& text_color) : font_size(font_size), value(value), font_name(font_name), text_color(text_color)
{
}

string RichLabel::getText() const
{
	return value;
}
