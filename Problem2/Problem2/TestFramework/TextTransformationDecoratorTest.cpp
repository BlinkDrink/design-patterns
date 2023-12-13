#include "pch.h"

#include "../Problem2/CapitalizeTransformation.h"
#include "../Problem2/CensorTransformation.h"
#include "../Problem2/DecorateTransformation.h"
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
	using std::vector;
	using std::make_unique;
	using Problem2::Decorators::TextTransformationDecorator;
	using Problem2::TextTransformations::CapitalizeTransformation;
	using Problem2::TextTransformations::LeftTrimTransformation;
	using Problem2::TextTransformations::RightTrimTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::NormalizeSpaceTransformation;
	using Problem2::TextTransformations::TextTransformation;
	using Problem2::TextTransformations::CensorTransformation;
	using Problem2::TextTransformations::DecorateTransformation;
	using Problem2::Labels::Label;
	using Problem2::Labels::SimpleLabel;

	namespace DecoratorTests
	{
		class TextTransformationDecoratorTest : public ::testing::Test {
		protected:
			unique_ptr<Label> label1;
			unique_ptr<Label> label2;
			unique_ptr<TextTransformation> transformation1;
			unique_ptr<TextTransformation> transformation2;
			string base_text = "some  text";

			void SetUp() override {
				label1 = make_unique<SimpleLabel>(base_text);
				label2 = make_unique<SimpleLabel>(base_text);
				transformation1 = make_unique<CapitalizeTransformation>();
				transformation2 = make_unique<CapitalizeTransformation>();
			}

			void TearDown() override {

			}
		};

		TEST_F(TextTransformationDecoratorTest, Apply_CapitalizeTransformation) {
			// Arrange
			const string expected = "Some  text";
			const TextTransformationDecorator decorator1(label1, transformation1);

			// Act
			string actual = decorator1.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_CensorTransformation) {
			// Arrange
			const string expected = "**me  text";
			unique_ptr<TextTransformation> tt = make_unique<CensorTransformation>("so");
			const TextTransformationDecorator decorator1(label1, tt);

			// Act
			string actual = decorator1.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_ReplaceTransformation) {
			// Arrange
			const string expected = "awesome  text";
			unique_ptr<TextTransformation> tt = make_unique<ReplaceTransformation>("so", "aweso");
			const TextTransformationDecorator decorator1(label1, tt);

			// Act
			string actual = decorator1.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_NormalizeSpaceTransformation) {
			// Arrange
			const string expected = "some text";
			unique_ptr<TextTransformation> tt = make_unique<NormalizeSpaceTransformation>();
			const TextTransformationDecorator decorator1(label1, tt);

			// Act
			string actual = decorator1.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_LeftTrimTransformation) {
			// Arrange
			unique_ptr<TextTransformation> ltt = make_unique<LeftTrimTransformation>();
			unique_ptr<Label> l = make_unique<SimpleLabel>(" " + base_text);
			const TextTransformationDecorator decorator(l, ltt);
			const string expected = "some  text";

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_RightTrimTransformation) {
			// Arrange
			unique_ptr<TextTransformation> ltt = make_unique<RightTrimTransformation>();
			unique_ptr<Label> l = make_unique<SimpleLabel>(base_text + " ");
			const TextTransformationDecorator decorator(l, ltt);
			const string expected = "some  text";

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_DecorateTransformation) {
			// Arrange
			unique_ptr<TextTransformation> ltt = make_unique<DecorateTransformation>();
			unique_ptr<Label> l = make_unique<SimpleLabel>(base_text);
			const TextTransformationDecorator decorator(l, ltt);
			const string expected = "-={ some  text }=-";

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Correct_Comparison_Of_TextTransformations) {
			// Arrange
			const TextTransformationDecorator decorator1(label1, transformation1);
			const TextTransformationDecorator decorator2(label2, transformation2);

			// Assert
			EXPECT_EQ(decorator1, decorator2);
		}

		TEST_F(TextTransformationDecoratorTest, Correct_TransformationApplication_With_ChainedDecorators) {
			// Arrange
			const string expected = "Awesome  text";
			unique_ptr<Label> label = make_unique<SimpleLabel>(base_text);
			unique_ptr<TextTransformation> tt = make_unique<ReplaceTransformation>("so", "aweso");
			label = make_unique<TextTransformationDecorator>(label, tt);
			label = make_unique<TextTransformationDecorator>(label, transformation1);

			// Act
			string actual = label->getText();

			// Assert
			EXPECT_EQ(expected, actual);
		}

		TEST_F(TextTransformationDecoratorTest, Correct_TransformationApplication_AfterRemoval_Of_Decorator) {
			// Arrange
			const string expected = "Awesome  text";
			unique_ptr<Label> label = make_unique<SimpleLabel>(base_text);
			unique_ptr<TextTransformation> tt = make_unique<ReplaceTransformation>("so", "aweso");
			label = make_unique<TextTransformationDecorator>(label, tt);
			label = make_unique<TextTransformationDecorator>(label, transformation1);
			//label = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(label, typeid(TextTransformationDecorator));

			// Act
			string actual = label->getText();

			// Assert
			EXPECT_EQ(expected, actual);
		}
	}
}
