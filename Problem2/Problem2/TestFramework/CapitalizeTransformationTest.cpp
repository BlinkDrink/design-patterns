#include "pch.h"
#include "../Problem2/CapitalizeTransformation.h"
#include "../Problem2/CapitalizeTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::CapitalizeTransformation;

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
	}
}
