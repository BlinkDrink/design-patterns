#include "pch.h"

#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/LeftTrimTransformation.h"
#include "../Problem2/LeftTrimTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::LeftTrimTransformation;
	using Problem2::TextTransformations::DecorateTransformation;

	namespace TextTransformationTests
	{
		const string expected = "value";
		const string input = " value";

		TEST(LeftTrimTransformation, Correct_Deletion_Of_Leading_Whitespace) {
			// Arrange
			const LeftTrimTransformation s;

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}

		TEST(LeftTrimTransformation, LeftTrim_KeepsStringSame_WithNoLeadingSpaces) {
			// Arrange
			const LeftTrimTransformation s;

			// Assert
			EXPECT_EQ(expected, s.transform(expected));
		}

		TEST(LeftTrimTransformation, Correct_Comparison_Of_SameLeftTrimTransformations) {
			// Arrange
			LeftTrimTransformation s1;
			LeftTrimTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_TRUE(check);
		}

		TEST(LeftTrimTransformation, Correct_Comparison_Of_DifferentLeftTrimTransformations) {
			// Arrange
			LeftTrimTransformation s1;
			const DecorateTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}
	}
}
