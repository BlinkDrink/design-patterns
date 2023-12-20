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
			HelpLabel(unique_ptr<Label> implementation, string help_text);
			string getText() const override;
			string getHelpText() const;
			bool operator==(const Label& other) const override;
			// TODO: setter
		};
	}
}


