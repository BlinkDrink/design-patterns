#include "pch.h"
#include "../Problem1/Utils.h"

namespace TestFramework
{
	namespace UtilsTests
	{
		using Problem1::Utils::remove_trailing_zeroes;

		TEST(Utils, CorrectRemovalOfTrailingZeroes)
		{
			// Arrange
			constexpr double p = 2.75;
			string s = std::to_string(p);
			const string expected = "2.75";

			// Act
			remove_trailing_zeroes(s);

			// Assert
			EXPECT_EQ(s, expected);
		}
	}
}