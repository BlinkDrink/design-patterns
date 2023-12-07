#include "pch.h"
#include "../Problem2/RightTrimTransformation.h"
#include "../Problem2/RightTrimTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::RightTrimTransformation;

	namespace TextTransformationTests
	{
		const string expected = "value";
		const string input = "value ";

		TEST(RightTrimTransformation, Correct_Deletion_Of_Trailing_Whitespace) {
			// Arrange
			RightTrimTransformation s;

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}
	}
}
