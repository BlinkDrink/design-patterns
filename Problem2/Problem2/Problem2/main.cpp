#include <iostream>

#include "CapitalizeTransformation.h"
#include "CensorTransformation.h"
#include "Label.h"
#include "LabelPrinter.h"
#include "ReplaceTransformation.h"
#include "SimpleLabel.h"
#include "TextTransformationDecorator.h"

using namespace Problem2;

int main()
{
	std::unique_ptr<Labels::Label> label = std::make_unique<Labels::SimpleLabel>("Hello world!    Hi ");
	std::unique_ptr<TextTransformations::TextTransformation> tt = std::make_unique<TextTransformations::CensorTransformation>("l");
	std::unique_ptr<TextTransformations::TextTransformation> tt2 = std::make_unique<TextTransformations::ReplaceTransformation>("H", "y");

	label = std::make_unique<Decorators::TextTransformationDecorator>(label, tt);
	label = std::make_unique<Decorators::TextTransformationDecorator>(label, tt2);

	LabelPrinters::LabelPrinter lp;
	lp.print(*label);



	return 0;
}
