#include "pch.h"

#include "../Problem2/CapitalizeTransformation.h"
#include "../Problem2/CensorTransformation.h"
#include "../Problem2/LeftTrimTransformation.h"
#include "../Problem2/NormalizeSpaceTransformation.h"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/RightTrimTransformation.h"
#include "../Problem2/SimpleLabel.h"
#include "../Problem2/TextTransformationDecorator.h"
#include "../Problem2/TextTransformationDecorator.cpp"

namespace TestFramework
{
	using std::unique_ptr;
	using std::make_unique;
	using Problem2::Decorators::TextTransformationDecorator;
	using Problem2::TextTransformations::CapitalizeTransformation;
	using Problem2::TextTransformations::LeftTrimTransformation;
	using Problem2::TextTransformations::RightTrimTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::NormalizeSpaceTransformation;
	using Problem2::TextTransformations::TextTransformation;
	using Problem2::Labels::Label;
	using Problem2::Labels::SimpleLabel;

	namespace DecoratorTests
	{
		TEST(TextTransformationDecorator, Apply_CapitalizeTransformation) {
			// Arrange
			unique_ptr<Label> label = make_unique<SimpleLabel>("some text");
			unique_ptr<TextTransformation> capitalizeTransform = std::make_unique<CapitalizeTransformation>();
			const TextTransformationDecorator decorator(label, capitalizeTransform);
			const string expected = "Some text";

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST(TextTransformationDecorator, Apply_LeftTrimTransformation) {
			// Arrange
			unique_ptr<Label> label = make_unique<SimpleLabel>(" some text");
			unique_ptr<TextTransformation> ltt = std::make_unique<LeftTrimTransformation>();
			const TextTransformationDecorator decorator(label, ltt);
			const string expected = "some text";

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}
	}
}
