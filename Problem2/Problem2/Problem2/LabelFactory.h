#pragma once
#include <memory>
#include <vector>

#include "HelpLabel.h"
#include "Label.h"
#include "LabelDecoratorBase.h"
#include "LabelTypes.h"

namespace Problem2
{
	namespace Factories
	{
		using std::unique_ptr;
		using std::shared_ptr;
		using std::vector;
		using Labels::Label;
		using Labels::HelpLabel;
		using Labels::LabelType;
		using Decorators::LabelDecoratorBase;
		using TextTransformations::TextTransformation;


		class LabelFactory
		{
		public:
			unique_ptr<HelpLabel> addHelpText(unique_ptr<Label> label, const string& help_message) const;
			unique_ptr<Label> createSimpleLabel(const string& text) const;
			unique_ptr<Label> createRichLabel(const string& text, const string& font_name, const string& font_color, const unsigned short font_size) const;
			unique_ptr<Label> createProxyLabel(int timeout) const;
			unique_ptr<Label> addTextDecoratorTo(unique_ptr<Label> label, shared_ptr<TextTransformation> transformation) const;
			unique_ptr<Label> addRotatingDecoratorTo(unique_ptr<Label> label, vector<shared_ptr<TextTransformation>>& transformations) const;
			unique_ptr<Label> addRandomDecoratorTo(unique_ptr<Label> label, vector<shared_ptr<TextTransformation>>& transformations, long long seed) const;
		};
	}
}


