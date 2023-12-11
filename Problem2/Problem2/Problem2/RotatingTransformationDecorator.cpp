#include "RotatingTransformationDecorator.h"

namespace Problem2
{
	namespace Decorators
	{
		RotatingTransformationDecorator::RotatingTransformationDecorator(unique_ptr<Label>& next,
			vector<unique_ptr<TextTransformation>>& transformations)
			: LabelDecoratorBase(next), m_rotator(0), m_transformations(std::move(transformations))
		{
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
	}
}

