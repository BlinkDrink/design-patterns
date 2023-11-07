#include "pch.h"

#include "../Problem1/Triangle.h"
#include "../Problem1/Triangle.cpp"


TEST(Triangle, CorrectPerimeterCalculation)
{
	// Arrange
	const Triangle t(2.75, 3.25, 10);
	const double expected = 16;

	// Act
	const double p = t.perimeter();

	// Assert
	EXPECT_EQ(expected, p);
}

TEST(Triangle, CorrectTriangleComparison)
{
	// Arrange
	const Triangle t1(2.75, 3.25, 10);
	const Triangle t2(3.25, 10, 2.75);

	// Assert
	EXPECT_EQ(t1, t2);
}