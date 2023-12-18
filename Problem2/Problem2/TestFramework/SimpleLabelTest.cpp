#include "pch.h"
#include "../Problem2/SimpleLabel.h"
#include "../Problem2/SimpleLabel.cpp"

namespace TestFramework
{
	using Problem2::Labels::SimpleLabel;

	namespace LabelTests
	{
		const string expected = "value";

		TEST(SimpleLabel, Correct_Return_Of_Value) {
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
	}
}
