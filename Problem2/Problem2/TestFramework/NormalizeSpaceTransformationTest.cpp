#include "pch.h"
#include "../Problem2/NormalizeSpaceTransformation.h"
#include "../Problem2/NormalizeSpaceTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::NormalizeSpaceTransformation;

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
	}
}
