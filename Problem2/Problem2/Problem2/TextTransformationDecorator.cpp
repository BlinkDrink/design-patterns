#include "TextTransformationDecorator.h"

namespace Problem2
{
	namespace Decorators
	{
		TextTransformationDecorator::TextTransformationDecorator(unique_ptr<Label>& label,
			unique_ptr<TextTransformation>& tt) : LabelDecoratorBase(label), m_transformation(std::move(tt))
		{
		}

		string TextTransformationDecorator::getText() const
		{
			if (m_label && m_transformation)
			{
				return m_transformation->transform(m_label->getText());
			}

			if (m_label && !m_transformation)
			{
				return m_label->getText();
			}

			return "";
		}
	}
}

