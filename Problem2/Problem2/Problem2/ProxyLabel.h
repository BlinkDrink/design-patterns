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
			string getText() const override;
			bool operator==(const Label& other) const override;
		};
	}
}


