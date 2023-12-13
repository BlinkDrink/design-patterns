#include "RandomTransformationDecorator.h"


namespace Problem2
{
	namespace Decorators
	{
		RandomTransformationDecorator::RandomTransformationDecorator(unique_ptr<Label>& next, vector<unique_ptr<TextTransformation>>& tts, long long seed) : LabelDecoratorBase(next), m_transformations(std::move(tts)), seed(seed), m_re(seed)
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
				return m_transformations[m_igenerator(m_re)]->transform(m_label->getText());
			}

			return m_label->getText();
		}

		bool RandomTransformationDecorator::operator==(const Label& other) const
		{
			const RandomTransformationDecorator* cast = dynamic_cast<const RandomTransformationDecorator*>(&other);
			if (!cast)
				return false;

			if (m_transformations.size() != cast->m_transformations.size())
				return false;

			for (size_t i = 0; i < m_transformations.size(); ++i)
			{
				if (!(*m_transformations[i] == *(cast->m_transformations[i])))
					return false;
			}

			return *m_label == *(cast->m_label) && seed == cast->seed;
		}
	}
}
