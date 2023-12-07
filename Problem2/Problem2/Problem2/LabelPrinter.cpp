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
	}
}
