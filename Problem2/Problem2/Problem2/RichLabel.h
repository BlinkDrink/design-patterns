#pragma once

#include "Label.h"

namespace Problem2
{
	namespace Labels
	{
		class RichLabel : public Label
		{
		private:
			string m_text;
			string m_font_name;
			string m_text_color;
			unsigned short m_font_size;

		public:
			RichLabel(string value, string font_name, string text_color, unsigned short font_size);

			/**
			 * \return - m_text
			 */
			string getText() const override;

			/**
			 * \brief Equality operator - uses dynamic cast
			 * \param other - the object the comparison is done against
			 * \return true if the other object is of type RichLabel and their private fields match
			 * the current private fields
			 */
			bool operator==(const Label& other) const override;
		};
	}
}

