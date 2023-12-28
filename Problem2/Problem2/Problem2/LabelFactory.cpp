#include<sstream>

#include "LabelFactory.h"
#include "ProxyLabel.h"
#include "RichLabel.h"
#include "SimpleLabel.h"
#include "CapitalizeTransformation.h"
#include "TextTransformationDecorator.h"
#include "RandomTransformationDecorator.h"
#include "RotatingTransformationDecorator.h"

namespace Problem2
{
	namespace Factories
	{
		using std::make_unique;
		using std::make_shared;
		using std::istringstream;
		using Labels::SimpleLabel;
		using Labels::RichLabel;
		using Labels::ProxyLabel;
		using Decorators::TextTransformationDecorator;
		using Decorators::RotatingTransformationDecorator;
		using Decorators::RandomTransformationDecorator;

		unique_ptr<HelpLabel> LabelFactory::add_help_text_to(unique_ptr<Label> label, const string& help_message) const
		{
			return make_unique<HelpLabel>(std::move(label), help_message);
		}

		unique_ptr<Label> LabelFactory::create_label(const string& input) const
		{
			istringstream iss(input);
			string type;
			iss >> type;

			if (type == "simple")
			{
				string text;
				if (!(iss >> text))
					throw std::invalid_argument("Arguments for SimpleLabel were insufficient or of invalid type");

				return make_unique<SimpleLabel>(text);
			}
			if (type == "rich")
			{
				string text, font_name, text_color;
				unsigned short font_size;
				if (!(iss >> text >> font_name >> text_color >> font_size))
					throw std::invalid_argument("Arguments for RichLabel were insufficient or of invalid type");

				return make_unique<RichLabel>(text, font_name, text_color, font_size);
			}
			if (type == "proxy")
			{
				int timeout;
				if (!(iss >> timeout))
					throw std::invalid_argument("Arguments for ProxyLabel were insufficient or of invalid type");

				return make_unique<ProxyLabel>(timeout);
			}

			throw std::invalid_argument("Invalid label type");
		}

		unique_ptr<Label> LabelFactory::addTextDecoratorTo(unique_ptr<Label> label,
			shared_ptr<TextTransformation> transformation) const
		{
			return make_unique<TextTransformationDecorator>(std::move(label), std::move(transformation));
		}

		unique_ptr<Label> LabelFactory::addRotatingDecoratorTo(unique_ptr<Label> label,
			vector<shared_ptr<TextTransformation>>& transformations) const
		{
			return make_unique<RotatingTransformationDecorator>(std::move(label), transformations);
		}

		unique_ptr<Label> LabelFactory::addRandomDecoratorTo(unique_ptr<Label> label,
			vector<shared_ptr<TextTransformation>>& transformations, long long seed) const
		{
			return make_unique<RandomTransformationDecorator>(std::move(label), transformations, seed);
		}
	}
}
