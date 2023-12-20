#pragma once
#include "LabelDecoratorBase.h"

namespace Problem2
{
	namespace Decorators
	{
		/**
		 * \brief Simple text decorator applying only one TextTransformation on the underlying Label
		 */
		class TextTransformationDecorator : public LabelDecoratorBase
		{
		private:
			unique_ptr<TextTransformation> m_transformation;
		public:
			TextTransformationDecorator(unique_ptr<Label> label, unique_ptr<TextTransformation> tt);

			/**
			 * \brief Applies the given transformation on the underlying label after it performs its getText operation
			 * \return - the newly transformed string
			 */
			string getText() const override;

			/**
			 * \brief Comparator - uses dynamic_cast
			 * \param other - the object the comparison is done against
			 * \return - true if the underlying label and transformation match, false otherwise
			 */
			bool operator==(const Label& other) const override;

			unique_ptr<Label> removeDecorator(const type_info& decoratorType) override;
		};
	}
}

