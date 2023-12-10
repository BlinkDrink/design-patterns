#pragma once
#include <ctime>
#include <random>
#include <vector>

#include "LabelDecoratorBase.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::vector;
		using std::default_random_engine;
		using std::uniform_int_distribution;

		class RandomTransformationDecorator : public LabelDecoratorBase
		{
		private:
			vector<unique_ptr<TextTransformation>> _transformations;
			mutable default_random_engine _re;
			mutable uniform_int_distribution<int> _igenerator;
		public:
			RandomTransformationDecorator(unique_ptr<Label>& next, vector<unique_ptr<TextTransformation>>& tts, long long seed = time(nullptr));

			/**
			 * \brief Apply a random transformation from the list of transformation each time
			 * getText() gets called
			 * \return - newly transformed string following these rules
			 */
			string getText() const override;
		};
	}
}


