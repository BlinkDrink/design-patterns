#include "pch.h"
#include "../Problem2/RichLabel.h"
#include "../Problem2/RichLabel.cpp"
#include "../Problem2/SimpleLabel.h"

namespace TestFramework
{
	using Problem2::Labels::RichLabel;

	namespace LabelTests
	{
		const string expected = "value";
		const unsigned short font_size = 5;
		const string font_name = "font_name";
		const string text_color = "red";

		TEST(RichLabel, Correct_Return_Of_Value) {
			// Arrange
			const RichLabel s(expected, font_name, text_color, font_size);

			// Assert
			EXPECT_EQ(expected, s.getText());
		}

		TEST(RichLabel, Correct_Comparison_SameRichLabels) {
			// Arrange
			const RichLabel s1(expected, font_name, text_color, font_size);
			const RichLabel s2(expected, font_name, text_color, font_size);

			// Assert
			EXPECT_EQ(s1, s2);
		}

		TEST(RichLabel, Correct_Comparison_DifferentRichLabels) {
			// Arrange
			const RichLabel s1(expected, font_name, text_color, font_size);
			const RichLabel s2(expected + "a", font_name, text_color, font_size);

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(RichLabel, ComparisonBetween_RichLabel_AndLabelOfDifferentType_ReturnsFalse) {
			// Arrange
			const RichLabel s1(expected, font_name, text_color, font_size);
			const Problem2::Labels::SimpleLabel s2("new text");

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(RichLabel, Comparison_OfRichLabel_WithItself_ReturnsTrue) {
			// Arrange
			const RichLabel s(expected, font_name, text_color, font_size);

			// Assert
			EXPECT_EQ(s, s);
		}
	}
}
