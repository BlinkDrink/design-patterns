#include "pch.h"
#include "../Problem1/Utils.h"

TEST(Utils, CorrectRemovalOfTrailingZeroes)
{
	// Arrange
	constexpr double p = 2.75;
	string s = std::to_string(p);
	const string expected = "2.75";

	// Act
	removeTrailingZeroes(s);

	// Assert
	EXPECT_EQ(s, expected);
}

TEST(Utils, CorrectGeneretaionInGivenBounds)
{
	// Arrange
	constexpr double lower_bound = 5, upper_bound = 100;

	// Act
	double p = generateRandomDoubleNumber(lower_bound, upper_bound);
	bool check = p > lower_bound && p < upper_bound;
	bool expected = true;

	// Assert
	EXPECT_EQ(check, expected);
}