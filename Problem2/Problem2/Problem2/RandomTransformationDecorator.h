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
			long long seed;
		public:

			/**
			 * \brief
			 * \param next Constructor. Throws if transformations vector is empty
			 * \param transformations - vector containing the transformations that will be applied on the text
			 * \param seed - the default_random_engine seed value
			 */
			RandomTransformationDecorator(unique_ptr<Label> next, const vector<shared_ptr<TextTransformation>>& transformations, long long seed = time(nullptr));

			/**
			 * \brief Apply a random transformation from the list of transformation each time
			 * getText() gets called
			 * \return - newly transformed string following these rules
			 */
			string getText() const override;

			/**
			 * \brief Equality operator - uses dynamic_cast. Checks only if m_transformations and seed match other's m_transformation and seed
			 * \param other - the object the comparison is done against
			 * \return - true if the other object is of type RandomTransformationDecorator and their m_transformations
			 * and seed match the current m_transformations and seed
			 */
			bool operator==(const Label& other) const override;

			/**
			 * \brief Check if the chain of decorators contains toRemove and remove it
			 * \param toRemove - the decorator that will be removed (if found)
			 * \return - the decorator chain after the removal of toRemove
			 */
			unique_ptr<Label> removeDecorator(const LabelDecoratorBase& toRemove) override;
		};
	}
}


