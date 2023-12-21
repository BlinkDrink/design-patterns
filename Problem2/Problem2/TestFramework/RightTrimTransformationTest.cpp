#include "pch.h"

#include "../Problem2/LeftTrimTransformation.h"
#include "../Problem2/RightTrimTransformation.h"
#include "../Problem2/RightTrimTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::RightTrimTransformation;
	using Problem2::TextTransformations::LeftTrimTransformation;

	namespace TextTransformationTests
	{
		const string expected = "value";
		const string input = "value ";

		TEST(RightTrimTransformation, Correct_Deletion_Of_Trailing_Whitespace) {
			// Arrange
			const RightTrimTransformation s;

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}

		TEST(RightTrimTransformation, RightTrim_KeepsStringSame_WithNoTrailingSpaces) {
			// Arrange
			const RightTrimTransformation s;

			// Assert
			EXPECT_EQ(expected, s.transform(expected));
		}

		TEST(RightTrimTransformation, Correct_Comparison_Of_SameRightTrimTransformations) {
			// Arrange
			const RightTrimTransformation s1;
			const RightTrimTransformation s2;

			// Assert
			EXPECT_EQ(s1, s2);
		}

		TEST(RightTrimTransformation, Correct_Comparison_Of_DifferentRightTrimTransformations) {
			// Arrange
			const RightTrimTransformation s1;
			const LeftTrimTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}
	}
}
