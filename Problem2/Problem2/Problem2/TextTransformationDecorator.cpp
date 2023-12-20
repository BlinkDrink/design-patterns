#include "TextTransformationDecorator.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::logic_error;
		using std::make_unique;

		TextTransformationDecorator::TextTransformationDecorator(unique_ptr<Label> label,
			shared_ptr<TextTransformation> tt) : LabelDecoratorBase(std::move(label)), m_transformation(tt)
		{
			if (!m_label)
				throw invalid_argument("Reference to decorated object cannot be null");

			if (!m_transformation)
				throw invalid_argument("Reference to text transformation object cannot be null when creating TextTransformationDecorator");
		}

		string TextTransformationDecorator::getText() const
		{
			if (m_label && m_transformation)
			{
				return m_transformation->transform(m_label->getText());
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

			return *m_transformation == *cast->m_transformation;
		}

		unique_ptr<Label> TextTransformationDecorator::removeDecorator(const LabelDecoratorBase& toRemove)
		{
			if (*this == toRemove)
			{
				return std::move(m_label);
			}

			LabelDecoratorBase* decorator = dynamic_cast<LabelDecoratorBase*>(m_label.get());
			if (decorator) {
				m_label = decorator->removeDecorator(toRemove);
				return make_unique<TextTransformationDecorator>(std::move(m_label), std::move(m_transformation));
			}

			return make_unique<TextTransformationDecorator>(std::move(m_label), std::move(m_transformation));
		}
	}
}

