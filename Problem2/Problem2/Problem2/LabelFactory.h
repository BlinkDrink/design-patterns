#pragma once
#include <memory>

#include "HelpLabel.h"
#include "Label.h"
#include "LabelDecoratorBase.h"
#include "LabelTypes.h"

namespace Problem2
{
	namespace Factories
	{
		using std::unique_ptr;
		using Labels::Label;
		using Labels::HelpLabel;
		using Labels::LabelType;
		using Decorators::LabelDecoratorBase;

		class LabelFactory
		{
		private:

		public:
			unique_ptr<HelpLabel> addHelpText(unique_ptr<Label> label) const;
			unique_ptr<Label> createLabel(bool with_help_text, LabelType label_type) const;
			unique_ptr<Label> addDecoratorTo(unique_ptr<Label> label, unique_ptr<LabelDecoratorBase> decorator) const;
		};
	}
}


