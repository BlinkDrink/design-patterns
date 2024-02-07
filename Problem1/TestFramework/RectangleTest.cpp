#include "pch.h"

#include "../Problem1/Circle.h"
#include "../problem1/Rectangle.h"
#include "../problem1/Rectangle.cpp"


namespace TestFramework
{
	namespace RectangleTests
	{
		using Problem1::Figures::FigureType;
		using Problem1::Figures::Figure;
		using Problem1::Figures::Circle;
		using Problem1::Figures::Rectangle;

		TEST(Rectangle, Constructor_Throw_Non_Positive_Arguments)
		{
			// Assert
			EXPECT_THROW(Rectangle t(-4.25, 7.75), std::invalid_argument);
			EXPECT_THROW(Rectangle t(2.75, -5.11), std::invalid_argument);
			EXPECT_THROW(Rectangle t(2.75, 0), std::invalid_argument);
			EXPECT_THROW(Rectangle t(0, 2.75), std::invalid_argument);
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

		TEST(Rectangle, Correct_Rectangle_Comparison)
		{
			// Arrange
			const Rectangle t1(2.75, 3.25);
			const Rectangle t2(3.25, 2.75);

			// Assert
			EXPECT_EQ(t1, t2);
		}

		TEST(Rectangle, Correct_Rectangle_Comparison_With_Other_Figures)
		{
			// Arrange
			const Rectangle t1(2.75, 3.25);
			const Circle t2(3.25);
			const bool expected = false;

			// Act
			bool check = t1 == t2;

			// Assert
			EXPECT_EQ(check, expected);
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

		TEST(Rectangle, Correct_FigureType_Getter)
		{
			// Arrange
			const Rectangle t(2.75, 3.25);
			constexpr FigureType expected = FigureType::RectangleType;

			// Act
			const FigureType actual = t.figureType();

			// Assert
			EXPECT_EQ(expected, actual);
		}
	}
}
