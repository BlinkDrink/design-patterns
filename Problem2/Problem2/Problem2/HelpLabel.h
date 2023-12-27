#pragma once
#include <memory>

#include "Label.h"

namespace Problem2
{
	namespace Labels
	{
		using std::unique_ptr;

		class HelpLabel : public Label
		{
		private:
			unique_ptr<Label> m_imp;
			string m_help_text;
		public:

			/**
			 * \brief HelpLabel constructor. Uses dependency injection for m_imp
			 * \param implementation - the specific label implementation that will receive help text
			 * \param help_text - the help message that the HelpLabel will give
			 */
			HelpLabel(unique_ptr<Label> implementation, string help_text);

			/**
			 * \brief Calls getText() of the underlying label (m_imp)
			 */
			string getText() const override;

			/**
			 * \return - the private data member m_help_text
			 */
			string getHelpText() const;

			/**
			 * \brief Equality operator - uses dynamic cast
			 * \param other - the object the comparison is done against
			 * \return true if the other object is of type HelpLabel and their m_imp and m_help_text match
			 * the current m_imp and m_help_text
			 */
			bool operator==(const Label& other) const override;

			/**
			 * \brief Setter
			 * \param help_text - the new value for the m_help_text field
			 */
			void setHelpText(string help_text);
		};
	}
}


