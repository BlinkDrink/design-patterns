#include "pch.h"

#include "../Problem1/Triangle.h"
#include "../Problem1/Triangle.cpp"
#include "../Problem1/Utils.cpp"

TEST(Triangle, Constructor_NoThrow_Correct_Arguments)
{
	// Assert
	EXPECT_NO_THROW(Triangle t(2.75, 3.25, 5));
}

TEST(Triangle, Constructor_Throw_Incorrect_Arguments)
{
	// Assert
	EXPECT_THROW(Triangle t(2.75, 3.25, 10), invalid_argument);
}

TEST(Triangle, Constructor_Sorts_Field_Members)
{
	// Arrange
	Triangle t(4,3,5);
	string expected = "triangle 3 4 5";

	// Act
	string stringified = t.toString();

	// Assert
	EXPECT_EQ(stringified, expected);
}

TEST(Triangle, Correct_Perimeter_Calculation)
{
	// Arrange
	const Triangle t(2.75, 3.25, 5);
	const double expected = 11;

	// Act
	const double p = t.perimeter();

	// Assert
	EXPECT_EQ(expected, p);
}

TEST(Triangle, Correct_Triangle_Comparison)
{
	// Arrange
	const Triangle t1(2.75, 3.25, 5);
	const Triangle t2(3.25, 5, 2.75);

	// Assert
	EXPECT_EQ(t1, t2);
}

TEST(Triangle, Correct_Stringification_Of_Triangle)
{
	// Arrange
	const Triangle t1(2.75, 3.25, 5);
	const Triangle t2(3.25, 5, 2.75);
	const string expected = "triangle 2.75 3.25 5";

	// Act
	const string actualT1 = t1.toString();
	const string actualT2 = t2.toString();

	// Assert
	EXPECT_EQ(expected, actualT1);
	EXPECT_EQ(expected, actualT2);
}

TEST(Triangle, Correct_Clone_Of_Triangle)
{
	// Arrange
	const Triangle t1(2.75, 3.25,5);

	// Act
	const Triangle* t2 = t1.clone();

	// Assert
	EXPECT_EQ(t1, *t2);
	delete t2;
}