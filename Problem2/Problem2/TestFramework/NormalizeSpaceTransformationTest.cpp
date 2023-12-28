#include "pch.h"
#include "../Problem2/LeftTrimTransformation.h"
#include "../Problem2/NormalizeSpaceTransformation.h"
#include "../Problem2/NormalizeSpaceTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::NormalizeSpaceTransformation;
	using Problem2::TextTransformations::LeftTrimTransformation;

	namespace TextTransformationTests
	{
		const string expected = " value is good";
		const string input1 = "    value      is      good";
		const string input2 = " value    is      good       ";

		TEST(NormalizeSpaceTransformation, Correct_Replacement_Of_Consecutive_Spaces) {
			// Arrange
			NormalizeSpaceTransformation s;

			// Assert
			EXPECT_EQ(expected, s.transform(input1));
			EXPECT_EQ(expected + " ", s.transform(input2));
		}

		TEST(NormalizeSpaceTransformation, NormalizeSpace_KeepsStringSame_With_No_Consecutive_Spaces) {
			// Arrange
			NormalizeSpaceTransformation s;

			// Assert
			EXPECT_EQ(expected, s.transform(expected));
		}

		TEST(NormalizeSpaceTransformation, Correct_Comparison_Of_SameNormalizeSpaceTransformations) {
			// Arrange
			NormalizeSpaceTransformation s1;
			NormalizeSpaceTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_TRUE(check);
		}

		TEST(NormalizeSpaceTransformation, Correct_Comparison_Of_DifferentNormalizeSpaceTransformations) {
			// Arrange
			NormalizeSpaceTransformation s1;
			LeftTrimTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(NormalizeSpaceTransformation, ComparisonOf_NormalizeSpaceTransformation_WithItself_ReturnsTrue) {
			// Arrange
			const NormalizeSpaceTransformation s1;

			// Assert
			EXPECT_EQ(s1, s1);
		}
	}
}
