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
			LabelFactory label_factory;
			TextTransformationFactory ttf;
			LabelPrinter label_printer;

			vector<shared_ptr<TextTransformation>> tt{ ttf.create_transformation("censor o"), ttf.create_transformation("decorate") };

			unique_ptr<Label> label = label_factory.createRichLabel("hello", "font_name", "font_color", 15);
			label = label_factory.addTextDecoratorTo(std::move(label), ttf.create_transformation("censor l"));
			label = label_factory.addTextDecoratorTo(std::move(label), ttf.create_transformation("capitalize"));
			label = label_factory.addRotatingDecoratorTo(std::move(label), tt);
			label = label_factory.addRandomDecoratorTo(std::move(label), tt, time(nullptr));

			unique_ptr<HelpLabel> help_label = label_factory.add_help_text_to(std::move(label), "I am helpful");
			for (int i = 0; i < 10; ++i)
			{
				label_printer.printWithHelpText(*help_label);
			}
		}
	}
}

