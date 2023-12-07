#pragma once
#include "Label.h"

namespace Problem2
{
	namespace Labels
	{
		class SimpleLabel : public Label
		{
		private:
			string value;

		public:
			SimpleLabel(const string& value);

			string getText() const override;
		};
	}
}

