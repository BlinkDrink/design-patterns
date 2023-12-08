#pragma once
#include "LabelDecoratorBase.h"

namespace Problem2
{
	namespace Decorators
	{
		class TextTransformationDecorator : public LabelDecoratorBase
		{
		public:
			TextTransformationDecorator(unique_ptr<Label>& next)
				: LabelDecoratorBase(next)
			{
			}

			string getText() const override;
		};
	}
}

