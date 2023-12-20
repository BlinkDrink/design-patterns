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
		using std::shared_ptr;
		using std::default_random_engine;
		using std::uniform_int_distribution;

		class RandomTransformationDecorator : public LabelDecoratorBase
		{
		private:
			vector<shared_ptr<TextTransformation>> m_transformations;
			mutable uniform_int_distribution<int> m_igenerator;
			mutable default_random_engine m_re;
			long long seed = time(nullptr);
		public:
			RandomTransformationDecorator(unique_ptr<Label> next, vector<shared_ptr<TextTransformation>>& transformations, long long seed);

			/**
			 * \brief Apply a random transformation from the list of transformation each time
			 * getText() gets called
			 * \return - newly transformed string following these rules
			 */
			string getText() const override;
			bool operator==(const Label& other) const override;

			unique_ptr<Label> removeDecorator(const LabelDecoratorBase& toRemove) override;
		};
	}
}


