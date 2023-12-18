#include "TextTransformationDecorator.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::logic_error;
		using std::make_unique;

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

		bool TextTransformationDecorator::operator==(const Label& other) const
		{
			if (this == &other)
				return true;

			const TextTransformationDecorator* cast = dynamic_cast<const TextTransformationDecorator*>(&other);
			if (!cast)
				return false;

			return *m_transformation == *cast->m_transformation && *m_label == *cast->m_label;
		}

		unique_ptr<Label> TextTransformationDecorator::removeDecorator(const type_info& decoratorType)
		{
			if (typeid(*this) == decoratorType)
			{
				return std::move(m_label);
			}

			LabelDecoratorBase* decorator = dynamic_cast<LabelDecoratorBase*>(m_label.get());
			if (decorator) {
				m_label = decorator->removeDecorator(decoratorType);
				return std::make_unique<TextTransformationDecorator>(m_label, m_transformation);
			}

			return std::make_unique<TextTransformationDecorator>(m_label, m_transformation);
		}
	}
}

