#include "RotatingTransformationDecorator.h"

namespace Problem2
{
	namespace Decorators
	{
		RotatingTransformationDecorator::RotatingTransformationDecorator(unique_ptr<Label>& next,
			vector<unique_ptr<TextTransformation>>& transformations)
			: LabelDecoratorBase(next), m_rotator(0)
		{
			for (unique_ptr<TextTransformation>& transformation : transformations)
			{
				m_transformations.push_back(std::move(transformation));
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

			if (m_label) {
				return m_label->getText();
			}

			return "";
		}

		bool RotatingTransformationDecorator::operator==(const Label& other) const
		{
			const RotatingTransformationDecorator* cast = dynamic_cast<const RotatingTransformationDecorator*>(&other);
			if (!cast)
				return false;

			if (m_transformations.size() != cast->m_transformations.size())
				return false;

			for (size_t i = 0; i < m_transformations.size(); ++i)
			{
				if (!(*m_transformations[i] == *(cast->m_transformations[i])))
					return false;
			}

			return *m_label == *(cast->m_label) && m_rotator == cast->m_rotator;
		}
	}
}

