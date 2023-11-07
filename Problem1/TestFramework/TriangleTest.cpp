#include "pch.h"

#include "../Problem1/Triangle.h"
#include "../Problem1/Triangle.cpp"


TEST(Triangle, CorrectPerimeterCalculation)
{
	// Arrange
	const Triangle t(2.75, 3.25, 5);
	const double expected = 11;

	// Act
	const double p = t.perimeter();

	// Assert
	EXPECT_EQ(expected, p);
}

TEST(Triangle, CorrectTriangleComparison)
{
	// Arrange
	const Triangle t1(2.75, 3.25, 5);
	const Triangle t2(3.25, 5, 2.75);

	// Assert
	EXPECT_EQ(t1, t2);
}

TEST(Triangle, CorrectStringificationOfTriangle)
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