#include "pch.h"

#include "../Problem2/RichLabel.h"
#include "../Problem2/SimpleLabel.h"
#include "../Problem2/SimpleLabel.cpp"

namespace TestFramework
{
	using Problem2::Labels::SimpleLabel;

	namespace LabelTests
	{
		const string expected = "value";

		TEST(SimpleLabel, GetText_ReturnsCorrectResult) {
			// Arrange
			const SimpleLabel s(expected);

			// Assert
			EXPECT_EQ(expected, s.getText());
		}

		TEST(SimpleLabel, Correct_Comparison_SameSimpleLabels) {
			// Arrange
			const SimpleLabel s(expected);
			const SimpleLabel s1(expected);

			// Assert
			EXPECT_EQ(s1, s);
		}

		TEST(SimpleLabel, Correct_Comparison_DifferentSimpleLabels) {
			// Arrange
			const SimpleLabel s(expected);
			const SimpleLabel s1(expected + "abc");

			// Act
			const bool check = s == s1;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(SimpleLabel, Comparison_OfSimpleLabel_WithItself_ReturnsTrue) {
			// Arrange
			const SimpleLabel s(expected);

			// Assert
			EXPECT_EQ(s, s);
		}

		TEST(SimpleLabel, ComparisonBetween_SimpleLabel_AndLabelOfDifferentType_ReturnsFalse) {
			// Arrange
			const Problem2::Labels::RichLabel s1(expected, "font_name", "font_color", 10);
			const SimpleLabel s2("new text");

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}
	}
}
