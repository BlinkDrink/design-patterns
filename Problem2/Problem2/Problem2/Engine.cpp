#include "Engine.h"
#include <iostream>
#include<vector>

#include "CensorTransformation.h"
#include "CensorTransformationFactory.h"
#include "LabelFactory.h"
#include "RandomTransformationDecorator.h"
#include "SimpleLabel.h"
#include "TextTransformationDecorator.h"

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
		using TextTransformations::TextTransformation;

		Engine& Engine::getInstance()
		{
			static Engine instance;
			return instance;
		}

		void Engine::exe()
		{
			LabelFactory lf;

			vector<shared_ptr<TextTransformation>> tt{ lf.createCensorTransformation("o"), lf.createDecorateTransformation() };

			unique_ptr<Label> label = lf.createSimpleLabel("hello");
			label = lf.addTextDecoratorTo(label, lf.createCensorTransformation("l"));
			label = lf.addTextDecoratorTo(label, lf.createCapitalizeTransformation());
			label = lf.addRotatingDecoratorTo(label, tt);
			label = lf.addRandomDecoratorTo(label, tt, time(nullptr));

			unique_ptr<Labels::HelpLabel> hl = lf.addHelpText(label, "I am helpful");
			for (int i = 0; i < 10; ++i)
			{
				cout << hl->getHelpText() << " and also I have text: " << hl->getText() << endl;
			}
		}
	}
}

