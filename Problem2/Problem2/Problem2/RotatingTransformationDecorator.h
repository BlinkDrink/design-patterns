#pragma once
#include <vector>

#include "LabelDecoratorBase.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::vector;


		/**
		 * \brief Concrete Decorator
		 */
		class RotatingTransformationDecorator : public LabelDecoratorBase
		{
		private:
			mutable size_t m_rotator;
			vector<unique_ptr<TextTransformation>> m_transformations;
		public:
			RotatingTransformationDecorator(unique_ptr<Label>& next, vector<unique_ptr<TextTransformation>>& transformations);

			/**
			 * \brief On the first call, applies the first transformation in the list m_transformations
			 * then applies the next one in order and so on
			 * \return - newly transformed string
			 */
			string getText() const override;
			bool operator==(const Label& other) const override;

			unique_ptr<Label> removeDecoratorFrom(Label& from, Label& toRemove, type_info& decoratorType) override;
			unique_ptr<Label> removeDecorator(Label& toRemove, type_info& decoratorType) override;
		};
	}
}

