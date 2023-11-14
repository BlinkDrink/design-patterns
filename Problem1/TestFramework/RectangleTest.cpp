#include "pch.h"

#include "../problem1/Rectangle.h"
#include "../problem1/Rectangle.cpp"

using Problem1::Figures::Rectangle;
using Problem1::Figures::Figure;

namespace TestFramework
{
	namespace RectangleTests
	{

		TEST(Rectangle, Constructor_Throw_Negative_Arguments)
		{
			// Assert
			EXPECT_THROW(Rectangle t(-4.25, 7.75), std::invalid_argument);
			EXPECT_THROW(Rectangle t(2.75, -5.11), std::invalid_argument);
		}

		TEST(Rectangle, Constructor_Sorts_Field_Members)
		{
			// Arrange
			Rectangle t(4, 3);
			string expected = "rectangle 3 4";

			// Act
			string stringified = t.toString();

			// Assert
			EXPECT_EQ(stringified, expected);
		}

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
			const string expected = t1.toString();

			// Act
			const unique_ptr<Figure> t2 = t1.clone();
			const string actual = t2->toString();

			// Assert
			EXPECT_EQ(expected, actual);
		}
	}
}
