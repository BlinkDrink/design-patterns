#pragma once
#include <memory>

#include "Label.h"
#include "TextTransformation.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::unique_ptr;
		using Labels::Label;
		using TextTransformations::TextTransformation;

		class LabelDecoratorBase : public Label
		{
		private:
			unique_ptr<Label> _label;
			unique_ptr<TextTransformation> _transformation;
		public:
			LabelDecoratorBase(unique_ptr<Label>& next) : _label(std::move(next)) {}
			virtual string getText() const = 0;
		};
	}
}
