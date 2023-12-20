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
	using std::make_unique;
	using std::vector;

	namespace LabelTests
	{
		const string expected = "value";
		const string expected_help_message = "help message";
		const string input = "abc_def_abc_def";
		const string A = "abc";
		const string B = "def";

		TEST(HelpLabel, Correct_Return_Of_Values) {
			// Arrange
			unique_ptr<Label> l = std::make_unique<SimpleLabel>(expected);
			const HelpLabel s(std::move(l), expected_help_message);

			// Assert
			EXPECT_EQ(expected, s.getText());
			EXPECT_EQ(expected_help_message, s.getHelpText());
		}

		TEST(HelpLabel, Correct_ReturnOfValues_WithDecorators) {
			// Arrange
			string expected2 = "***_***_***_***";
			string expected3 = "-={ def_def_def_def }=-";
			unique_ptr<TextTransformation> tt = make_unique<ReplaceTransformation>(A, B);
			unique_ptr<TextTransformation> tt1 = make_unique<CensorTransformation>(B);
			unique_ptr<TextTransformation> tt2 = make_unique<DecorateTransformation>();
			vector<unique_ptr<TextTransformation>> vtt;
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

		TEST(HelpLabel, Correct_Comparison_SameHelpLabels) {
			// Arrange
			unique_ptr<Label> l1 = std::make_unique<SimpleLabel>(expected);
			const HelpLabel s1(std::move(l1), expected_help_message);
			l1 = std::make_unique<SimpleLabel>(expected);
			const HelpLabel s2(std::move(l1), expected_help_message);

			// Assert
			EXPECT_EQ(s1, s2);
		}

		TEST(HelpLabel, Correct_Comparison_DifferentHelpLabels) {
			// Arrange
			unique_ptr<Label> l1 = std::make_unique<SimpleLabel>(expected + "a");
			const HelpLabel s1(std::move(l1), expected_help_message);
			l1 = std::make_unique<SimpleLabel>(expected);
			const HelpLabel s2(std::move(l1), expected_help_message);

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}
	}
}
