#pragma once
#include "Label.h"

namespace Problem2
{
	namespace Labels
	{
		class HelpLabel : public Label
		{
		private:
			string m_text;
			string m_help_text;
		public:
			string getText() const override;
			string getHelpText() const;
			bool operator==(const Label& other) const override;
		};
	}
}


