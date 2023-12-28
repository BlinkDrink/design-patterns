#include "Engine.h"
#include <iostream>
#include<vector>

#include "CensorTransformationFactory.h"
#include "LabelFactory.h"
#include "LabelPrinter.h"
#include "RandomTransformationDecorator.h"

namespace Problem2
{
	namespace Engines
	{
		using std::vector;
		using std::unique_ptr;
		using std::shared_ptr;

		using Labels::Label;
		using Factories::LabelFactory;
		using LabelPrinters::LabelPrinter;
		using Labels::HelpLabel;
		using TextTransformations::TextTransformation;
		using Factories::TextTransformationFactory;

		Engine& Engine::getInstance()
		{
			static Engine instance;
			return instance;
		}

		void Engine::exe()
		{
			TextTransformationFactory ttf;
			vector<shared_ptr<TextTransformation>> tt{ ttf.create_transformation("censor o"), ttf.create_transformation("decorate") };

			unique_ptr<Label> label = LabelFactory::getInstance().create_label("rich hello font_name font_color 15");
			label = LabelFactory::getInstance().add_text_decorator_to(std::move(label), ttf.create_transformation("censor l"));
			label = LabelFactory::getInstance().add_text_decorator_to(std::move(label), ttf.create_transformation("capitalize"));
			label = LabelFactory::getInstance().add_rotating_decorator_to(std::move(label), tt);
			label = LabelFactory::getInstance().add_random_decorator_to(std::move(label), tt, time(nullptr));

			const unique_ptr<HelpLabel> help_label = LabelFactory::getInstance().add_help_text_to(std::move(label), "I am helpful");
			for (int i = 0; i < 10; ++i)
			{
				LabelPrinter::printWithHelpText(*help_label);
			}
		}
	}
}

