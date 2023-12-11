#include "RandomTransformationDecorator.h"

#include <pplinterface.h>

namespace Problem2
{
	namespace Decorators
	{
		RandomTransformationDecorator::RandomTransformationDecorator(unique_ptr<Label>& next, vector<unique_ptr<TextTransformation>>& tts, long long seed) : LabelDecoratorBase(next), m_transformations(std::move(tts)), m_re(seed)
		{
			if (!m_transformations.empty())
			{
				m_igenerator = uniform_int_distribution<int>(0, m_transformations.size() - 1);
			}
		}

		string RandomTransformationDecorator::getText() const
		{
			if (!m_transformations.empty())
			{
				int index = m_igenerator(m_re);
				return m_transformations[index]->transform(m_label->getText());
			}

			return m_label->getText();
		}
	}
}