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
			bool operator==(const Label& other) const override;
			unique_ptr<Label> removeDecorator(const LabelDecoratorBase& toRemove) override;
		};
	}
}

