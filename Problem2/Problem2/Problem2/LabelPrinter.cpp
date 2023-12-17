#include "LabelPrinter.h"

namespace Problem2
{
	using Labels::Label;

	namespace LabelPrinters
	{
		void LabelPrinter::print(const Label& label)
		{
			cout << label.getText();
		}

		void LabelPrinter::printWithHelpText(const Labels::HelpLabel& label)
		{
			print(label);
			cout << "Some help information about this label: " << label.getHelpText();
		}
	}
}
