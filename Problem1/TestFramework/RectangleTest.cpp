#include "pch.h"

#include "../problem1/Rectangle.h"
#include "../problem1/Rectangle.cpp"

TEST(Rectangle, CorrectPerimeterCalculation)
{
	// arrange
	const Rectangle t(2.50, 3.25);
	const double expected = 11.50;

	// act
	const double p = t.perimeter();

	// assert
	EXPECT_EQ(expected, p);
}


TEST(Rectangle, CorrectRectangleComparison)
{
	// Arrange
	const Rectangle t1(2.75, 3.25);
	const Rectangle t2(3.25, 2.75);

	// Assert
	EXPECT_EQ(t1, t2);
}

TEST(Rectangle, CorrectStringificationOfRectangle)
{
	// Arrange
	const Rectangle t1(2.75, 3.25);
	const Rectangle t2(3.25, 2.75);
	const string expected = "rectangle 2.75 3.25";

	// Act
	const string actualT1 = t1.toString();
	const string actualT2 = t2.toString();

	// Assert
	EXPECT_EQ(expected, actualT1);
	EXPECT_EQ(expected, actualT2);
}

TEST(Rectangle, CorrectCloneOfObject)
{
	// Arrange
	const Rectangle t1(2.75, 3.25);

	// Act
	const Rectangle* t2 = t1.clone();

	// Assert
	EXPECT_EQ(t1, *t2);
	delete t2;
}