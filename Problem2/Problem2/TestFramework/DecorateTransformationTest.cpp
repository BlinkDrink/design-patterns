#include "pch.h"
#include "../Problem2/LeftTrimTransformation.h"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/DecorateTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::DecorateTransformation;
	using Problem2::TextTransformations::LeftTrimTransformation;

	namespace TextTransformationTests
	{
		const string expected = "-={ value }=-";
		const string input = "value";

		TEST(DecorateTransformation, Correct_Decoration_Of_String) {
			// Arrange
			const DecorateTransformation s;

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}

		TEST(DecorateTransformation, Correct_Comparison_Of_SameDecorateTransformations) {
			// Arrange
			DecorateTransformation s1;
			DecorateTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_TRUE(check);
		}

		TEST(DecorateTransformation, Correct_Comparison_Of_DifferentDecorateTransformations) {
			// Arrange
			DecorateTransformation s1;
			LeftTrimTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(DecorateTransformation, ComparisonOf_DecorateTransformation_WithItself_ReturnsTrue) {
			// Arrange
			const DecorateTransformation s1;

			// Assert
			EXPECT_EQ(s1, s1);
		}
	}
}
