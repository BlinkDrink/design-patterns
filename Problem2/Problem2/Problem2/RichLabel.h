#pragma once

#include "Label.h"

namespace Problem2
{
	namespace Labels
	{
		class RichLabel : public Label
		{
		private:
			unsigned short _font_size;
			string _value;
			string _font_name;
			string _text_color;

		public:
			RichLabel(const string& value, unsigned short font_size, const string& font_name, const string& text_color);

			string getText() const override;
		};
	}
}

