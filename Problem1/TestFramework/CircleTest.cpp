#include "pch.h"
#include <corecrt_math_defines.h>

#include "../Problem1/Circle.h"
#include "../Problem1/Circle.cpp"

TEST(Circle, CorrectPerimeterCalculation)
{
	// Arrange
	const Circle t(3);
	const double expected = 2* M_PI * 3;

	// Act	
	const double p = t.perimeter();

	// Assert
	EXPECT_EQ(expected, p);
}

TEST(Circle, CorrectCircleComparison)
{
	// Arrange
	const Circle t1(2.75);
	const Circle t2(2.75);

	// Assert
	EXPECT_EQ(t1, t2);
}

TEST(Circle, CorrectStringificationOfCircle)
{
	// Arrange
	const Circle t1(2.75);
	const Circle t2(3.25);
	const string expected1 = "circle 2.75";
	const string expected2 = "circle 3.25";


	// Act
	const string actualT1 = t1.toString();
	const string actualT2 = t2.toString();

	// Assert
	EXPECT_EQ(expected1, actualT1);
	EXPECT_EQ(expected2, actualT2);
}

TEST(Circle, CorrectCloneOfObject)
{
	// Arrange
	const Circle t1(2.75);

	// Act
	const Circle* t2 = t1.clone();

	// Assert
	EXPECT_EQ(t1, *t2);
	delete t2;
}