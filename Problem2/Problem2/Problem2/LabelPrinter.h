#pragma once

#include <iostream>

#include "HelpLabel.h"
#include "Label.h"

using std::cout;

namespace Problem2
{
	using Labels::Label;

	namespace LabelPrinters
	{
		class LabelPrinter
		{
		public:
			static void print(const Label& label);
			static void printWithHelpText(const Labels::HelpLabel& label);

		};
	}
}
