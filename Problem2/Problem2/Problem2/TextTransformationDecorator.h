#pragma once
#include "LabelDecoratorBase.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::shared_ptr;

		/**
		 * \brief Simple text decorator applying only one TextTransformation on the underlying Label
		 */
		class TextTransformationDecorator : public LabelDecoratorBase
		{
		private:
			shared_ptr<TextTransformation> m_transformation;
		public:
			TextTransformationDecorator(unique_ptr<Label> label, const shared_ptr<TextTransformation>& tt);

			/**
			 * \brief Applies the given transformation on the underlying label after it performs its getText operation
			 * \return - the newly transformed string
			 */
			string getText() const override;

			/**
			 * \brief Equality operator - uses dynamic_cast
			 * \param other - the object the comparison is done against
			 * \return - true if the other object is of type TextTransformationDecorator and their m_transformation
			 * and matches the current m_transformation
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

