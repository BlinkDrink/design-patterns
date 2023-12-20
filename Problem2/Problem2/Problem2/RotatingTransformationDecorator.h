#pragma once
#include <vector>

#include "LabelDecoratorBase.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::vector;
		using std::shared_ptr;

		/**
		 * \brief Concrete Decorator
		 */
		class RotatingTransformationDecorator : public LabelDecoratorBase
		{
		private:
			vector<shared_ptr<TextTransformation>> m_transformations;
			mutable size_t m_rotator;
		public:
			RotatingTransformationDecorator(unique_ptr<Label> next, vector<shared_ptr<TextTransformation>>& transformations);

			/**
			 * \brief On the first call, applies the first transformation in the list m_transformations, on the second
			 * call applies the next one in order and so on
			 * \return - newly transformed string
			 */
			string getText() const override;

			/**
			 * \brief Equality operator - uses dynamic_cast. Checks only if m_transformations and m_rotator
			 * match other's m_transformation and m_rotator
			 * \param other - the object the comparison is done against
			 * \return - true if the other object is of type RotatingTransformationDecorator and their m_transformations
			 * and m_rotator match the current m_transformations and m_rotator
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

