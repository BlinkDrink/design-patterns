#include "pch.h"
#include "../Problem2/LeftTrimTransformation.h"
#include "../Problem2/LeftTrimTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::LeftTrimTransformation;

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
	}
}
