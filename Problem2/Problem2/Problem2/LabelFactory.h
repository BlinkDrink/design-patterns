#pragma once
#include <memory>
#include <vector>

#include "HelpLabel.h"
#include "Label.h"
#include "LabelDecoratorBase.h"
#include "TextTransformationFactory.h"

namespace Problem2
{
	namespace Factories
	{
		using std::unique_ptr;
		using std::shared_ptr;
		using std::vector;
		using Labels::Label;
		using Labels::HelpLabel;
		using Decorators::LabelDecoratorBase;
		using TextTransformations::TextTransformation;

		/**
		 * \brief Singleton
		 */
		class LabelFactory
		{
		private:
			LabelFactory() = default;
		public:
			/**
			 * \brief Adds help text to a given label
			 * \param label - the label on which help text will be added
			 * \param help_message - the contents of the help text
			 * \return - a label with help text added to it
			 */
			unique_ptr<HelpLabel> add_help_text_to(unique_ptr<Label> label, const string& help_message) const;

			/**
			 * \brief Creates a label based on some text input
			 * \param input - The type of label to create (e.g. simple this_is_my_simple_text, proxy 4, rich my_text my_font_name my_font_color my_font_size)
			 * \return - newly created label of the given type
			 */
			unique_ptr<Label> create_label(const string& input) const;

			/**
			 * \brief Adds a simple text decorator to a given label
			 * \param label - the label that the decorator will be attached to
			 * \param transformation - the transformation that the TextTransformationDecorator will use
			 * \return - a label that has a TextTransformationDecorator attached to it
			 */
			unique_ptr<Label> add_text_decorator_to(unique_ptr<Label> label, shared_ptr<TextTransformation> transformation) const;

			/**
			 * \brief Adds a RotatingTextDecorator to a given label
			 * \param label - the label that the decorator will be attached to
			 * \param transformations - the transformations that the TextTransformationDecorator will use
			 * \return - a label that has a RotatingTransformationDecorator attached to it
			 */
			unique_ptr<Label> add_rotating_decorator_to(unique_ptr<Label> label, vector<shared_ptr<TextTransformation>>& transformations) const;

			/**
			 * \brief Adds a RandomTextDecorator to a given label
			 * \param label - the label that the decorator will be attached to
			 * \param transformations - the transformations that the TextTransformationDecorator will use
			 * \param seed - the seed of the random generator that lies inside the RandomTransformationDecorator
			 * \return - a label that has a RandomTransformationDecorator attached to it
			 */
			unique_ptr<Label> add_random_decorator_to(unique_ptr<Label> label, vector<shared_ptr<TextTransformation>>& transformations, long long seed) const;

			static LabelFactory& getInstance();

			LabelFactory(const LabelFactory& other) = delete;
			LabelFactory& operator=(const LabelFactory& other) = delete;
			LabelFactory(LabelFactory&& other) = delete;
			LabelFactory& operator=(LabelFactory&& other) = delete;
		};
	}
}


