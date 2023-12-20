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
			LabelDecoratorBase(unique_ptr<Label> next);

			/**
			 * \brief Starts the process of decorator removal from a given decorator
			 * This is the algorithm on which Template Method Design Pattern is applied
			 * by overriding specific part of it in the derived classes
			 * \param from - starting point(label) from which decorator will be found and removed
			 * \param toRemove - the target decorator that will be removed
			 * \return - the chain of decorators starting with from, excluding toRemove (if it was found)
			 */
			static unique_ptr<Label> removeDecoratorFrom(unique_ptr<Label> from, const LabelDecoratorBase& toRemove);

			/**
			 * \brief Called inside of removeDecoratorFrom and overriden in deriving classes of LabelDecoratorBase
			 * Implements different logic for the different decorators
			 * \param toRemove - the target decorator that will be removed
			 * \return - the chain of decorators, excluding toRemove (if it was found)
			 */
			virtual unique_ptr<Label> removeDecorator(const LabelDecoratorBase& toRemove) = 0;

			virtual string getText() const override = 0;
			virtual bool operator==(const Label& other) const override = 0;

		};
	}
}
