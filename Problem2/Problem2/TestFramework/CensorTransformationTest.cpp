#include "pch.h"
#include "../Problem2/CensorTransformation.h"
#include "../Problem2/CensorTransformation.cpp"

namespace TestFramework
{
	using Problem2::TextTransformations::CensorTransformation;

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
	}
}
