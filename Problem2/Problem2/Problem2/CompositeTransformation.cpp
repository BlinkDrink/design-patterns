#include "CompositeTransformation.h"

#include <stdexcept>

namespace Problem2
{
	namespace Composites
	{
		using std::invalid_argument;

		bool CompositeTransformation::operator==(const TextTransformation& other)
		{
			const CompositeTransformation* cast = dynamic_cast<const CompositeTransformation*>(&other);
			if (!cast)
				return false;

			return m_transformations == cast->m_transformations;
		}

		void CompositeTransformation::add(unique_ptr<TextTransformation>& transformation)
		{
			if (!transformation)
				throw invalid_argument("Reference to added transformation cannot be null");

			m_transformations.push_back(std::move(transformation));
		}

		string CompositeTransformation::transform(string text) const
		{
			for (const unique_ptr<TextTransformation>& transformation : m_transformations)
			{
				text = transformation->transform(text);
			}

			return text;
		}
	}
}
