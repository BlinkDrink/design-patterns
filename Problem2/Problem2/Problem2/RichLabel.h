#pragma once

#include "Label.h"

namespace Problem2
{
	namespace Labels
	{
		class RichLabel : public Label
		{
		private:
			unsigned short m_font_size;
			string m_value;
			string m_font_name;
			string m_text_color;

		public:
			RichLabel(const string& value, unsigned short font_size, const string& font_name, const string& text_color);

			string getText() const override;
			bool operator==(const Label& other) const override;
		};
	}
}

