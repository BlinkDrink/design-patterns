#include "pch.h"
#include "../Problem2/CensorTransformation.h"
#include "../Problem2/CensorTransformation.cpp"
#include "../Problem2/DecorateTransformation.h"

namespace TestFramework
{
	using Problem2::TextTransformations::CensorTransformation;
	using Problem2::TextTransformations::DecorateTransformation;

	namespace TextTransformationTests
	{
		const string input = "abc-def_defabcdef";
		const string expected = "***-def_def***def";
		const string to_censor = "abc";

		TEST(CensorTransformation, Correct_Censoring_Of_String) {
			// Arrange
			const CensorTransformation s(to_censor);

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}

		TEST(CensorTransformation, Correct_Comparison_Of_SameCensorTransformations) {
			// Arrange
			CensorTransformation s1(to_censor);
			CensorTransformation s2(to_censor);

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_TRUE(check);
		}

		TEST(CensorTransformation, Correct_Comparison_Of_DifferentCensorTransformation) {
			// Arrange
			CensorTransformation s1(to_censor);
			CensorTransformation s2(to_censor + "d");

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(CensorTransformation, ComparisonOf_CensorTransformation_WithTransformationOfDifferentType_ReturnsFalse) {
			// Arrange
			CensorTransformation s1(to_censor);
			DecorateTransformation s2;

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST(CensorTransformation, ComparisonOf_CensorTransformation_WithItself_ReturnsTrue) {
			// Arrange
			const CensorTransformation s1(to_censor);

			// Assert
			EXPECT_EQ(s1, s1);
		}
	}
}
