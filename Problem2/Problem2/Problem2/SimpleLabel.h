#pragma once
#include "Label.h"

namespace Problem2
{
	namespace Labels
	{
		class SimpleLabel : public Label
		{
		private:
			string _value;

		public:
			SimpleLabel(const string& value);
			string getText() const override;
		};
	}
}

