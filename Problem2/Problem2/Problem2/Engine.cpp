#include "Engine.h"
#include <iostream>

#include "CensorTransformation.h"
#include "CensorTransformationFactory.h"
#include "RandomTransformationDecorator.h"
#include "SimpleLabel.h"
#include "TextTransformationDecorator.h"

namespace Problem2
{
	namespace Engines
	{
		using std::cout;
		using std::endl;

		void Engine::menu() const
		{

		}

		Engine& Engine::getInstance()
		{
			static Engine instance;
			return instance;
		}

		void Engine::exe()
		{
			static Factories::CensorTransformationFactory ctf;
			auto sp = ctf.createCensorTransformation("t");
			auto label = std::make_unique<Labels::SimpleLabel>("abc");
			auto decorator = std::make_unique<Decorators::TextTransformationDecorator>(std::move(label), std::move(sp));

		}
	}
}

