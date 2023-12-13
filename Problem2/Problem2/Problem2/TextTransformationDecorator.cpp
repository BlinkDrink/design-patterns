#include "TextTransformationDecorator.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::logic_error;

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

			throw logic_error("Reference to decorated object cannot be null when getting text");
		}

		bool TextTransformationDecorator::operator==(const Label& other)
		{
			const TextTransformationDecorator* cast = dynamic_cast<const TextTransformationDecorator*>(&other);
			if (!cast)
				return false;

			return *m_label == *(cast->m_label) && *m_transformation == *(cast->m_transformation);
		}
	}
}

