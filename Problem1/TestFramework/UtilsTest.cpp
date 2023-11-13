#include "pch.h"
#include "../Problem1/Utils.h"

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
