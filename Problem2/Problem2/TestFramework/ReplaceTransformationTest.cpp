#include "pch.h"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/ReplaceTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::ReplaceTransformation;

	namespace TextTransformationTests
	{
		const string expected = "_d_ddef";
		const string expected2 = "__def";
		const string input = "_abc_abcdef";
		const string A = "abc";
		const string B = "d";

		TEST(ReplaceTransformation, Correct_Replacement_Of_A_to_B) {
			// Arrange
			const ReplaceTransformation s(A, B);

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}

		TEST(ReplaceTransformation, ReplacementProducesUnalteredString_When_A_Equals_B) {
			// Arrange
			const ReplaceTransformation s(A, A);

			// Assert
			EXPECT_EQ(input, s.transform(input));
		}

		TEST(ReplaceTransformation, Correct_Replacement_With_Empty_Space) {
			// Arrange
			const ReplaceTransformation s(A, "");

			// Assert
			EXPECT_EQ(expected2, s.transform(input));
		}

		TEST(ReplaceTransformation, Correct_Comparison_Of_SameReplaceTransformations) {
			// Arrange
			const ReplaceTransformation s1(A, B);
			const ReplaceTransformation s2(A, B);

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_TRUE(check);
		}

		TEST(ReplaceTransformation, Correct_Comparison_Of_DifferentReplaceTransformations) {
			// Arrange
			const ReplaceTransformation s1(A, B);
			const ReplaceTransformation s2(B, A);

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(ReplaceTransformation, ComparisonOf_ReplaceTransformation_WithItself_ReturnsTrue) {
			// Arrange
			const ReplaceTransformation s1(A, B);

			// Assert
			EXPECT_EQ(s1, s1);
		}
	}
}
