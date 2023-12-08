#include "pch.h"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/ReplaceTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::ReplaceTransformation;

	namespace TextTransformationTests
	{
		const string expected = "_d_ddef";
		const string input = "_abc_abcdef";
		const string A = "abc";
		const string B = "d";

		TEST(ReplaceTransformation, Correct_Replacement_Of_A_to_B) {
			// Arrange
			ReplaceTransformation s(A, B);

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}
	}
}
