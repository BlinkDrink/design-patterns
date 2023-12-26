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
		using std::cout;
		using std::endl;
		using std::vector;
		using std::unique_ptr;
		using std::make_shared;
		using std::shared_ptr;

		using Labels::Label;
		using Factories::LabelFactory;
		using LabelPrinters::LabelPrinter;
		using Labels::HelpLabel;
		using TextTransformations::TextTransformation;

		Engine& Engine::getInstance()
		{
			static Engine instance;
			return instance;
		}

		void Engine::exe()
		{
			LabelFactory label_factory;
			LabelPrinter label_printer;

			vector<shared_ptr<TextTransformation>> tt{ label_factory.createCensorTransformation("o"), label_factory.createDecorateTransformation() };

			unique_ptr<Label> label = label_factory.createRichLabel("hello", "font_name", "font_color", 15);
			label = label_factory.addTextDecoratorTo(std::move(label), label_factory.createCensorTransformation("l"));
			label = label_factory.addTextDecoratorTo(std::move(label), label_factory.createCapitalizeTransformation());
			label = label_factory.addRotatingDecoratorTo(std::move(label), tt);
			label = label_factory.addRandomDecoratorTo(std::move(label), tt, time(nullptr));

			unique_ptr<HelpLabel> help_label = label_factory.addHelpTextTo(std::move(label), "I am helpful");
			for (int i = 0; i < 10; ++i)
			{
				label_printer.printWithHelpText(*help_label);
			}
		}
	}
}

