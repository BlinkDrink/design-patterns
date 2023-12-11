#pragma once
#include <memory>

#include "Label.h"
#include "TextTransformation.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::unique_ptr;
		using Labels::Label;
		using TextTransformations::TextTransformation;

		/**
		 * \brief Interface for all Decorator objects
		 */
		class LabelDecoratorBase : public Label
		{
		protected:
			unique_ptr<Label> m_label;
		public:
			LabelDecoratorBase(unique_ptr<Label>& next) : m_label(std::move(next)) {}

			virtual string getText() const override = 0;
		};
	}
}