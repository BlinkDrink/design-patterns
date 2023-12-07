#pragma once

#include <iostream>
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
			void print(const Label& label);
		};
	}
}
