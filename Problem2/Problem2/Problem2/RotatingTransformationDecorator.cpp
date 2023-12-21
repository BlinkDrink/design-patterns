#include "RotatingTransformationDecorator.h"

#include "TextTransformationDecorator.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::make_unique;
		using std::logic_error;

		RotatingTransformationDecorator::RotatingTransformationDecorator(unique_ptr<Label> next,
			vector<shared_ptr<TextTransformation>>& transformations)
			: LabelDecoratorBase(std::move(next)), m_rotator(0)
		{
			if (transformations.empty())
				throw invalid_argument("List of transformations cannot be empty");

			for (shared_ptr<TextTransformation>& transformation : transformations)
			{
				m_transformations.push_back(transformation);
			}
		}

		string RotatingTransformationDecorator::getText() const
		{
			if (m_label && !m_transformations.empty())
			{
				string res = m_transformations[m_rotator++]->transform(m_label->getText());
				if (m_rotator >= m_transformations.size())
					m_rotator = 0;
				return res;
			}

			throw logic_error("Reference to underlying label cannot be null");
		}

		bool RotatingTransformationDecorator::operator==(const Label& other) const
		{
			if (this == &other)
				return true;

			const RotatingTransformationDecorator* cast = dynamic_cast<const RotatingTransformationDecorator*>(&other);
			if (!cast)
				return false;

			if (m_transformations.size() != cast->m_transformations.size())
				return false;

			for (size_t i = 0; i < m_transformations.size(); ++i)
			{
				if (!(*m_transformations[i] == *cast->m_transformations[i]))
					return false;
			}

			return m_rotator == cast->m_rotator;
		}

		unique_ptr<Label> RotatingTransformationDecorator::removeDecorator(const LabelDecoratorBase& toRemove)
		{
			if (*this == toRemove)
			{
				return std::move(m_label);
			}

			LabelDecoratorBase* decorator = dynamic_cast<LabelDecoratorBase*>(m_label.get());
			if (decorator) {
				m_label = decorator->removeDecorator(toRemove);
				return make_unique<RotatingTransformationDecorator>(std::move(m_label), m_transformations);
			}

			return make_unique<RotatingTransformationDecorator>(std::move(m_label), m_transformations);
		}
	}
}

