#include "LabelFactory.h"

#include "CapitalizeTransformation.h"
#include "CensorTransformation.h"
#include "DecorateTransformation.h"
#include "LeftTrimTransformation.h"
#include "ProxyLabel.h"
#include "RandomTransformationDecorator.h"
#include "ReplaceTransformation.h"
#include "NormalizeSpaceTransformation.h"
#include "RichLabel.h"
#include "RightTrimTransformation.h"
#include "RotatingTransformationDecorator.h"
#include "SimpleLabel.h"
#include "TextTransformationDecorator.h"

namespace Problem2
{
	namespace Factories
	{
		using std::make_unique;
		using std::make_shared;
		using Labels::SimpleLabel;
		using Labels::RichLabel;
		using Labels::ProxyLabel;
		using Decorators::TextTransformationDecorator;
		using Decorators::RotatingTransformationDecorator;
		using Decorators::RandomTransformationDecorator;
		using TextTransformations::ReplaceTransformation;
		using TextTransformations::NormalizeSpaceTransformation;
		using TextTransformations::CapitalizeTransformation;
		using TextTransformations::LeftTrimTransformation;
		using TextTransformations::RightTrimTransformation;
		using TextTransformations::CensorTransformation;
		using TextTransformations::DecorateTransformation;

		unique_ptr<HelpLabel> LabelFactory::addHelpText(unique_ptr<Label>& label, const string& help_message) const
		{
			return make_unique<HelpLabel>(std::move(label), help_message);
		}

		unique_ptr<Label> LabelFactory::createSimpleLabel(const string& text) const
		{
			return make_unique<SimpleLabel>(text);
		}

		unique_ptr<Label> LabelFactory::createRichLabel(const string& text, const string& font_name, const string& font_color, const unsigned short font_size) const
		{
			return make_unique<RichLabel>(text, font_name, font_color, font_size);
		}

		unique_ptr<Label> LabelFactory::createProxyLabel(int timeout) const
		{
			return make_unique<ProxyLabel>(timeout);
		}

		unique_ptr<Label> LabelFactory::addTextDecoratorTo(unique_ptr<Label>& label,
			shared_ptr<TextTransformation> transformation) const
		{
			return make_unique<TextTransformationDecorator>(std::move(label), std::move(transformation));
		}

		unique_ptr<Label> LabelFactory::addRotatingDecoratorTo(unique_ptr<Label>& label,
			vector<shared_ptr<TextTransformation>>& transformations) const
		{
			return make_unique<RotatingTransformationDecorator>(std::move(label), transformations);
		}

		unique_ptr<Label> LabelFactory::addRandomDecoratorTo(unique_ptr<Label>& label,
			vector<shared_ptr<TextTransformation>>& transformations, long long seed) const
		{
			return make_unique<RandomTransformationDecorator>(std::move(label), transformations, seed);
		}

		shared_ptr<TextTransformation> LabelFactory::createReplaceTransformation(const string& from,
			const string& to) const
		{
			return make_shared<ReplaceTransformation>(from, to);
		}

		shared_ptr<TextTransformation> LabelFactory::createCensorTransformation(const string& to_censor)
		{
			return m_ctf.createCensorTransformation(to_censor);
		}

		shared_ptr<TextTransformation> LabelFactory::createNormalizeSpaceTransformation() const
		{
			return make_shared<NormalizeSpaceTransformation>();
		}

		shared_ptr<TextTransformation> LabelFactory::createLeftTrimTransformation() const
		{
			return make_shared<LeftTrimTransformation>();
		}

		shared_ptr<TextTransformation> LabelFactory::createRightTrimTransformation() const
		{
			return make_shared<RightTrimTransformation>();
		}

		shared_ptr<TextTransformation> LabelFactory::createDecorateTransformation() const
		{
			return make_shared<DecorateTransformation>();
		}

		shared_ptr<TextTransformation> LabelFactory::createCapitalizeTransformation() const
		{
			return make_shared<CapitalizeTransformation>();
		}
	}
}
