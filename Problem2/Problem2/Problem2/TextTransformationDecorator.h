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
			TextTransformationDecorator(unique_ptr<Label>& label, unique_ptr<TextTransformation>& tt);

			/**
			 * \brief Applies the given transformation on the underlying label after it performs its getText operation
			 * \return - the newly transformed string
			 */
			string getText() const override;
		};
	}
}

