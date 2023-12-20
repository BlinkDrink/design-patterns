#pragma once
#include <memory>

#include "Label.h"
#include "SimpleLabel.h"

namespace Problem2
{
	namespace Labels
	{
		using std::unique_ptr;

		class ProxyLabel : public Label
		{
		private:
			mutable unique_ptr<Label> m_real_label;
			mutable int m_timeout_threshold;
			mutable int m_request_count;
			mutable bool m_prompt_user;

		public:
			ProxyLabel(int timeout = 5);

			/**
			 * \brief Gets the text of the underlying label. m_real_label gets created when getText gets called for the first time
			 * After getText gets called timeout number of times a console input will be required in order to reset the text of the
			 * underlying label or keep it the same.
			 * \return - m_real_label's getText()
			 */
			string getText() const override;

			/**
			 * \brief Equality operator - uses dynamic_cast
			 * \param other - the object the comparison is done against
			 * \return - true if other is of type ProxyLabel and their m_real_label, m_timeout_threshold, m_request_count and m_prompt_user
			 * match the current ones
			 */
			bool operator==(const Label& other) const override;
		};
	}
}


