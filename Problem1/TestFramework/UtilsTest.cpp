#include "pch.h"
#include "../Problem1/Utils.h"

TEST(Utils, CorrectRemovalOfTrailingZeroes)
{
	// Arrange
	double p = 2.75;
	string s = std::to_string(p);
	string expected = "2.75";

	// Act
	removeTrailingZeroes(s);

	// Assert
	EXPECT_EQ(s, expected);
}