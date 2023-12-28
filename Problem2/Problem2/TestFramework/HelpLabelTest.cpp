#include "pch.h"

#include "../Problem2/CensorTransformation.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/HelpLabel.h"
#include "../Problem2/HelpLabel.cpp"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/RotatingTransformationDecorator.h"
#include "../Problem2/SimpleLabel.h"
#include "../Problem2/TextTransformation.h"
#include "../Problem2/TextTransformationDecorator.h"

namespace TestFramework
{
	using Problem2::Labels::Label;
	using Problem2::Labels::HelpLabel;
	using Problem2::Labels::SimpleLabel;
	using Problem2::TextTransformations::TextTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::Decorators::TextTransformationDecorator;
	using Problem2::Decorators::RotatingTransformationDecorator;
	using Problem2::TextTransformations::CensorTransformation;
	using Problem2::TextTransformations::DecorateTransformation;

	using std::unique_ptr;
	using std::shared_ptr;
	using std::make_shared;
	using std::make_unique;
	using std::vector;

	namespace LabelTests
	{
		const string expected = "value";
		const string expected_help_message = "help message";
		const string input = "abc_def_abc_def";
		const string A = "abc";
		const string B = "def";

		TEST(HelpLabel, Constructor_ThrowsInvalidArgumentException_WithNullptr_ToLabel) {
			// Assert
			EXPECT_THROW(HelpLabel s(nullptr, expected_help_message), std::invalid_argument);
		}

		TEST(HelpLabel, GetTextAndGetHelpText_ReturnsCorrectResult) {
			// Arrange
			unique_ptr<Label> l = std::make_unique<SimpleLabel>(expected);
			const HelpLabel s(std::move(l), expected_help_message);

			// Assert
			EXPECT_EQ(expected, s.getText());
			EXPECT_EQ(expected_help_message, s.getHelpText());
		}

		TEST(HelpLabel, GetTextAndGetHelpText_WithDecorators_ReturnsCorrectResult) {
			// Arrange
			const string expected2 = "***_***_***_***";
			const string expected3 = "-={ def_def_def_def }=-";
			shared_ptr<TextTransformation> tt = make_shared<ReplaceTransformation>(A, B);
			shared_ptr<TextTransformation> tt1 = make_shared<CensorTransformation>(B);
			shared_ptr<TextTransformation> tt2 = make_shared<DecorateTransformation>();
			vector<shared_ptr<TextTransformation>> vtt;
			vtt.push_back(std::move(tt1));
			vtt.push_back(std::move(tt2));

			unique_ptr<Label> l1 = std::make_unique<SimpleLabel>(input);
			l1 = make_unique<TextTransformationDecorator>(std::move(l1), std::move(tt));
			l1 = make_unique<RotatingTransformationDecorator>(std::move(l1), vtt);

			const HelpLabel s(std::move(l1), expected_help_message);

			// Assert
			EXPECT_EQ(expected2, s.getText());
			EXPECT_EQ(expected3, s.getText());
			EXPECT_EQ(expected_help_message, s.getHelpText());
		}

		TEST(HelpLabel, ComparisonBetween_SameHelpLabels_ReturnsTrue) {
			// Arrange
			unique_ptr<Label> l1 = make_unique<SimpleLabel>(expected);
			const HelpLabel s1(std::move(l1), expected_help_message);
			l1 = make_unique<SimpleLabel>(expected);
			const HelpLabel s2(std::move(l1), expected_help_message);

			// Assert
			EXPECT_EQ(s1, s2);
		}

		TEST(HelpLabel, Correct_Comparison_DifferentHelpLabels) {
			// Arrange
			unique_ptr<Label> l1 = make_unique<SimpleLabel>(expected + "a");
			const HelpLabel s1(std::move(l1), expected_help_message);
			l1 = make_unique<SimpleLabel>(expected);
			const HelpLabel s2(std::move(l1), expected_help_message);

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(HelpLabel, ComparisonBetween_HelpLabel_AndDifferentTypeLabel_ReturnsFalse) {
			// Arrange
			unique_ptr<Label> l1 = make_unique<SimpleLabel>(expected);
			const HelpLabel help_label(std::move(l1), expected_help_message);
			const SimpleLabel label("some text");

			// Act
			const bool check = label == help_label;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(HelpLabel, SetHelpMessage_CorrectlyChangesHelpMessage) {
			// Arrange
			unique_ptr<Label> l1 = make_unique<SimpleLabel>(expected);
			HelpLabel help_label(std::move(l1), expected_help_message);
			string expected = "new help text";

			// Act
			help_label.setHelpText(expected);

			// Assert
			EXPECT_EQ(help_label.getHelpText(), expected);
		}
	}
}
