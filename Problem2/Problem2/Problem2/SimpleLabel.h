#pragma once
#include "Label.h"

namespace Problem2
{
	namespace Labels
	{
		class SimpleLabel : public Label
		{
		private:
			string m_text;

		public:
			SimpleLabel(const string& value);


			/**
			 * \return - m_text
			 */
			string getText() const override;

			/**
			 * \brief Equality operator - uses dynamic cast
			 * \param other - the object the comparison is done against
			 * \return true if the other object is of type SimpleLabel and their private fields match
			 * the current private fields
			 */
			bool operator==(const Label& other) const override;
		};
	}
}

