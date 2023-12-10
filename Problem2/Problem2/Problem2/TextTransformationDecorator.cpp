#include "TextTransformationDecorator.h"

namespace Problem2
{
	namespace Decorators
	{
		TextTransformationDecorator::TextTransformationDecorator(unique_ptr<Label>& label,
			unique_ptr<TextTransformation>& tt) : LabelDecoratorBase(label), _transformation(std::move(tt))
		{
		}

		string TextTransformationDecorator::getText() const
		{
			if (_label && _transformation)
			{
				return _transformation->transform(_label->getText());
			}

			if (_label && !_transformation)
			{
				return _label->getText();
			}

			return "";
		}
	}
}

