#include "pch.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/CapitalizeTransformation.h"
#include "../Problem2/CapitalizeTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::CapitalizeTransformation;
	using Problem2::TextTransformations::DecorateTransformation;

	namespace TextTransformationTests
	{
		const string expected = "Value";
		const string input = "value";

		TEST(CapitalizeTransformation, Correct_Capitalization_Of_Value) {
			// Arrange
			CapitalizeTransformation s;

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}

		TEST(CapitalizeTransformation, Correct_Comparison_Of_SameCapitalizeTransformations) {
			// Arrange
			CapitalizeTransformation s1;
			CapitalizeTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_TRUE(check);
		}

		TEST(CapitalizeTransformation, Correct_Comparison_Of_DifferentCapitalizeTransformations) {
			// Arrange
			CapitalizeTransformation s1;
			const DecorateTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(CapitalizeTransformation, ComparisonOf_CapitalizeTransformation_WithItself_ReturnsTrue) {
			// Arrange
			const CapitalizeTransformation s1;

			// Assert
			EXPECT_EQ(s1, s1);
		}
	}
}
