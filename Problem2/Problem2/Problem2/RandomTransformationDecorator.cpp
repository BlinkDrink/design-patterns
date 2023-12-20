#include "RandomTransformationDecorator.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::make_unique;

		RandomTransformationDecorator::RandomTransformationDecorator(unique_ptr<Label> next, vector<shared_ptr<TextTransformation>>& transformations, long long seed) : LabelDecoratorBase(std::move(next)), m_re(seed)
		{
			if (!m_transformations.empty())
			{
				m_igenerator = uniform_int_distribution<int>(0, m_transformations.size() - 1);
			}

			for (shared_ptr<TextTransformation>& transformation : transformations)
			{
				m_transformations.push_back(std::move(transformation));
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
			if (this == &other)
				return true;

			const RandomTransformationDecorator* cast = dynamic_cast<const RandomTransformationDecorator*>(&other);
			if (!cast)
				return false;

			if (m_transformations.size() != cast->m_transformations.size())
				return false;

			for (size_t i = 0; i < m_transformations.size(); ++i)
			{
				if (!(*m_transformations[i] == *cast->m_transformations[i]))
					return false;
			}

			return seed == cast->seed;
		}

		unique_ptr<Label> RandomTransformationDecorator::removeDecorator(const LabelDecoratorBase& toRemove)
		{
			if (*this == toRemove)
			{
				return std::move(m_label);
			}

			LabelDecoratorBase* decorator = dynamic_cast<LabelDecoratorBase*>(m_label.get());
			if (decorator) {
				m_label = decorator->removeDecorator(toRemove);
				return make_unique<RandomTransformationDecorator>(std::move(m_label), m_transformations, seed);
			}

			return make_unique<RandomTransformationDecorator>(std::move(m_label), m_transformations, seed);
		}
	}
}
