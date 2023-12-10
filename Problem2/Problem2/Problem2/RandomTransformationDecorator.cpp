#include "RandomTransformationDecorator.h"

#include <pplinterface.h>

namespace Problem2
{
	namespace Decorators
	{
		using std::invalid_argument;

		RandomTransformationDecorator::RandomTransformationDecorator(unique_ptr<Label>& next, vector<unique_ptr<TextTransformation>>& tts, long long seed) : LabelDecoratorBase(next), _transformations(std::move(tts)), _re(seed)
		{
			if (!_transformations.empty())
			{
				_igenerator = uniform_int_distribution<int>(0, _transformations.size() - 1);
			}
		}

		string RandomTransformationDecorator::getText() const
		{
			if (!_transformations.empty())
			{
				int index = _igenerator(_re);
				return _transformations[index]->transform(_label->getText());
			}

			return _label->getText();
		}

	}
}
