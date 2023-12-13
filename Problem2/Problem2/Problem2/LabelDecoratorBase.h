#pragma once
#include <memory>
#include <stdexcept>

#include "Label.h"
#include "TextTransformation.h"

namespace Problem2
{
	namespace Decorators
	{
		using std::unique_ptr;
		using Labels::Label;
		using std::invalid_argument;
		using TextTransformations::TextTransformation;

		/**
		 * \brief Abstract class for all Decorator objects
		 */
		class LabelDecoratorBase : public Label
		{
		protected:
			unique_ptr<Label> m_label;
		public:
			LabelDecoratorBase(unique_ptr<Label>& next)
			{
				if (next == nullptr)
					throw invalid_argument("Reference to decorated object cannot be nullptr");
				m_label = std::move(next);
			}

			static unique_ptr<Label> removeDecoratorFrom(Label& from, const type_info& decoratorType)
			{
				LabelDecoratorBase* decorator = dynamic_cast<LabelDecoratorBase*>(&from);
				if (decorator)
				{
					return decorator->removeDecorator(decoratorType);
				}

				return nullptr;
			}
			virtual unique_ptr<Label> removeDecorator(const type_info& decoratorType) = 0;

			virtual string getText() const override = 0;
			virtual bool operator==(const Label& other) const override = 0;

		};
	}
}
