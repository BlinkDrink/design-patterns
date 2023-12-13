#include <iostream>

#include "CensorTransformation.h"
#include "DecorateTransformation.h"
#include "Label.h"
#include "LabelPrinter.h"
#include "LabelDecoratorBase.h"
#include "ReplaceTransformation.h"
#include "RotatingTransformationDecorator.h"
#include "SimpleLabel.h"
#include "TextTransformationDecorator.h"

int main()
{
	std::unique_ptr<Problem2::Labels::Label> label = std::make_unique<Problem2::Labels::SimpleLabel>("Hello world!    Hi ");
	std::unique_ptr<Problem2::TextTransformations::TextTransformation> tt = std::make_unique<Problem2::TextTransformations::CensorTransformation>("l");
	std::unique_ptr<Problem2::TextTransformations::TextTransformation> tt2 = std::make_unique<Problem2::TextTransformations::ReplaceTransformation>("H", "y");

	std::unique_ptr<Problem2::TextTransformations::TextTransformation> tt3 = std::make_unique<Problem2::TextTransformations::DecorateTransformation>();
	std::unique_ptr<Problem2::TextTransformations::TextTransformation> tt4 = std::make_unique<Problem2::TextTransformations::CensorTransformation>("o");

	std::vector<std::unique_ptr<Problem2::TextTransformations::TextTransformation>> v;
	v.push_back(std::move(tt3));
	v.push_back(std::move(tt4));

	label = std::make_unique<Problem2::Decorators::TextTransformationDecorator>(label, tt);
	label = std::make_unique<Problem2::Decorators::TextTransformationDecorator>(label, tt2);
	label = std::make_unique<Problem2::Decorators::RotatingTransformationDecorator>(label, v);

	Problem2::LabelPrinters::LabelPrinter lp;
	lp.print(*label);
	cout << std::endl;

	label = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(label, typeid(Problem2::Decorators::TextTransformationDecorator));
	lp.print(*label);
	cout << std::endl;
	label = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(label, typeid(Problem2::Decorators::TextTransformationDecorator));
	lp.print(*label);
	lp.print(*label);

	label = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(label, typeid(Problem2::Decorators::RotatingTransformationDecorator));
	cout << std::endl;
	lp.print(*label);

	return 0;
}
