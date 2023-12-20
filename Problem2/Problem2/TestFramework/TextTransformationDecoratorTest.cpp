#include "pch.h"

#include "../Problem2/CapitalizeTransformation.h"
#include "../Problem2/CensorTransformation.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/LeftTrimTransformation.h"
#include "../Problem2/NormalizeSpaceTransformation.h"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/RichLabel.h"
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
	using std::shared_ptr;
	using std::make_shared;

	namespace DecoratorTests
	{
		class TextTransformationDecoratorTest : public ::testing::Test {
		protected:
			unique_ptr<Label> label1;
			unique_ptr<Label> label2;
			unique_ptr<Label> label3;
			shared_ptr<TextTransformation> transformation1;
			shared_ptr<TextTransformation> transformation2;
			shared_ptr<TextTransformation> transformation3;
			string base_text = "some  text";
			string A = "abc";
			string B = "def";


			void SetUp() override {
				label1 = make_unique<SimpleLabel>(base_text);
				label2 = make_unique<SimpleLabel>(base_text);
				label3 = make_unique<SimpleLabel>(base_text + "abc");
				transformation1 = make_shared<CapitalizeTransformation>();
				transformation2 = make_shared<CapitalizeTransformation>();
				transformation3 = make_shared<ReplaceTransformation>(A, B);
			}

			void TearDown() override {

			}
		};

		TEST_F(TextTransformationDecoratorTest, Apply_CapitalizeTransformation_ReturnsCorrectResult) {
			// Arrange
			const string expected = "Some  text";
			TextTransformationDecorator decorator1(std::move(label1), std::move(transformation1));

			// Act
			string actual = decorator1.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_CensorTransformation_ReturnsCorrectResult) {
			// Arrange
			const string expected = "**me  text";
			unique_ptr<TextTransformation> tt = make_unique<CensorTransformation>("so");
			const TextTransformationDecorator decorator1(std::move(label1), std::move(tt));

			// Act
			string actual = decorator1.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_ReplaceTransformation_ReturnsCorrectResult) {
			// Arrange
			const string expected = "awesome  text";
			unique_ptr<TextTransformation> tt = make_unique<ReplaceTransformation>("so", "aweso");
			const TextTransformationDecorator decorator1(std::move(label1), std::move(tt));

			// Act
			string actual = decorator1.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_NormalizeSpaceTransformation_ReturnsCorrectResult) {
			// Arrange
			const string expected = "some text";
			unique_ptr<TextTransformation> tt = make_unique<NormalizeSpaceTransformation>();
			const TextTransformationDecorator decorator1(std::move(label1), std::move(tt));

			// Act
			string actual = decorator1.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_LeftTrimTransformation_ReturnsCorrectResult) {
			// Arrange
			unique_ptr<TextTransformation> ltt = make_unique<LeftTrimTransformation>();
			unique_ptr<Label> l = make_unique<SimpleLabel>(" " + base_text);
			const TextTransformationDecorator decorator(std::move(l), std::move(ltt));
			const string expected = "some  text";

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_RightTrimTransformation_ReturnsCorrectResult) {
			// Arrange
			unique_ptr<Label> l = make_unique<SimpleLabel>(base_text + " ");
			unique_ptr<TextTransformation> ltt = make_unique<RightTrimTransformation>();
			const TextTransformationDecorator decorator(std::move(l), std::move(ltt));
			const string expected = "some  text";

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Apply_DecorateTransformation_ReturnsCorrectResult) {
			// Arrange
			unique_ptr<TextTransformation> ltt = make_unique<DecorateTransformation>();
			unique_ptr<Label> l = make_unique<SimpleLabel>(base_text);
			TextTransformationDecorator decorator(std::move(l), std::move(ltt));
			const string expected = "-={ some  text }=-";

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST_F(TextTransformationDecoratorTest, Comparison_Of_SameTextTransformationDecorators_ReturnsTrue) {
			// Arrange
			const TextTransformationDecorator decorator1(std::move(label1), std::move(transformation1));
			const TextTransformationDecorator decorator2(std::move(label2), std::move(transformation2));

			// Assert
			EXPECT_EQ(decorator1, decorator2);
		}

		TEST_F(TextTransformationDecoratorTest, Comparison_Of_TextTransformationDecorators_WithDifferentUnderylingLabels_ReturnsTrue) {
			// Arrange
			const TextTransformationDecorator decorator1(std::move(label1), std::move(transformation1));
			const TextTransformationDecorator decorator2(std::move(label3), std::move(transformation2));

			// Assert
			EXPECT_EQ(decorator1, decorator2);
		}

		TEST_F(TextTransformationDecoratorTest, Comparison_Of_TextTransformationDectorators_WithDifferentTransformations_ReturnsFalse) {
			// Arrange
			const TextTransformationDecorator decorator1(std::move(label1), std::move(transformation1));
			const TextTransformationDecorator decorator2(std::move(label3), std::move(transformation3));

			// Act
			const bool check = decorator1 == decorator2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST_F(TextTransformationDecoratorTest, TransformationApplication_With_ChainedTextTransformationDecorators_ReturnsCorrectResult) {
			// Arrange
			const string expected = "Awesome  text";
			unique_ptr<Label> label = make_unique<SimpleLabel>(base_text);
			unique_ptr<TextTransformation> tt = make_unique<ReplaceTransformation>("so", "aweso");
			label = make_unique<TextTransformationDecorator>(std::move(label), std::move(tt));
			label = make_unique<TextTransformationDecorator>(std::move(label), std::move(transformation1));

			// Act
			string actual = label->getText();

			// Assert
			EXPECT_EQ(expected, actual);
		}

		TEST_F(TextTransformationDecoratorTest, TransformationApplication_AfterRemovalOfDecorator_ReturnsCorrectResult) {
			// Arrange
			const string expected = "Somk  tkxt";
			unique_ptr<Label> label = make_unique<SimpleLabel>(base_text);
			unique_ptr<TextTransformation> tt = make_unique<ReplaceTransformation>("so", "aweso");
			unique_ptr<TextTransformation> tt2 = make_unique<ReplaceTransformation>("e", "k");
			label = make_unique<TextTransformationDecorator>(std::move(label), std::move(tt));
			label = make_unique<TextTransformationDecorator>(std::move(label), std::move(transformation1));
			label = make_unique<TextTransformationDecorator>(std::move(label), std::move(tt2));
			const TextTransformationDecorator toRemove(make_unique<SimpleLabel>("something"), make_unique<ReplaceTransformation>("so", "aweso"));
			label = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(std::move(label), toRemove);

			// Act
			string actual = label->getText();

			// Assert
			EXPECT_EQ(expected, actual);
		}

		TEST_F(TextTransformationDecoratorTest, TransformationApplication_AfterRemovalOfAllDecorators_ReturnsCorrectResult) {
			// Arrange
			unique_ptr<Label> label = make_unique<SimpleLabel>(base_text);
			unique_ptr<TextTransformation> tt = make_unique<ReplaceTransformation>("so", "aweso");
			unique_ptr<TextTransformation> tt2 = make_unique<ReplaceTransformation>("e", "k");
			label = make_unique<TextTransformationDecorator>(std::move(label), std::move(tt));
			label = make_unique<TextTransformationDecorator>(std::move(label), std::move(transformation1));
			label = make_unique<TextTransformationDecorator>(std::move(label), std::move(tt2));
			const TextTransformationDecorator toRemove(make_unique<SimpleLabel>("something"), make_unique<ReplaceTransformation>("so", "aweso"));
			const TextTransformationDecorator toRemove2(make_unique<SimpleLabel>("something"), make_unique<CapitalizeTransformation>());
			const TextTransformationDecorator toRemove3(make_unique<SimpleLabel>("something"), make_unique<ReplaceTransformation>("e", "k"));
			label = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(std::move(label), toRemove);
			label = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(std::move(label), toRemove2);
			label = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(std::move(label), toRemove3);

			// Act
			string actual = label->getText();

			// Assert
			EXPECT_EQ(base_text, actual);
		}
	}
}
