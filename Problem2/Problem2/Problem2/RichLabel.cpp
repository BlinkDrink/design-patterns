#include "RichLabel.h"

RichLabel::RichLabel(const string& value, unsigned short font_size, const string& font_name, const string& text_color) : value(value), font_size(font_size), font_name(font_name), text_color(text_color)
{

}

string RichLabel::getText() const
{
	return value;
}
