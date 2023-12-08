#include "pch.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/DecorateTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::DecorateTransformation;

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
	}
}
