#include "pch.h"
#include <corecrt_math_defines.h>

#include "../Problem1/Rectangle.h"
#include "../Problem1/FigureType.h"
#include "../Problem1/Circle.h"
#include "../Problem1/Circle.cpp"


namespace TestFramework
{
	namespace CircleTests
	{
		using Problem1::Figures::Circle;
		using Problem1::Figures::Figure;
		using Problem1::Figures::Figure;
		using Problem1::Figures::Rectangle;
		using Problem1::Figures::FigureType;

		TEST(Circle, Correct_Perimeter_Calculation)
		{
			// Arrange
			const Circle t(3);
			const double expected = 2 * M_PI * 3;

			// Act	
			const double p = t.perimeter();
			const bool check = abs(p - expected) < DBL_EPSILON;

			// Assert
			EXPECT_EQ(check, true);
		}

		TEST(Circle, Constructor_Throw_Non_Positive_Arguments)
		{
			// Assert
			EXPECT_THROW(Circle t(-2.75), std::invalid_argument);
			EXPECT_THROW(Circle t(0), std::invalid_argument);
		}

		TEST(Circle, Correct_Circle_Comparison)
		{
			// Arrange
			const Circle t1(2.75);
			const Circle t2(2.75);

			// Assert
			EXPECT_EQ(t1, t2);
		}

		TEST(Circle, Correct_Circle_Comparison_With_Other_Figure)
		{
			// Arrange
			const Circle t1(2.75);
			const Rectangle t2(2.75, 3.66);
			bool expected = false;

			// Act
			bool check = t1 == t2;

			// Assert
			EXPECT_EQ(check, expected);
		}

		TEST(Circle, Correct_Stringification_Of_Circle)
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

		TEST(Circle, Correct_Clone_Of_Object)
		{
			// Arrange
			const Circle t1(2.75);
			string expected = t1.toString();

			// Act
			const unique_ptr<Figure> t2 = t1.clone();
			string actual = t2->toString();

			// Assert
			EXPECT_EQ(expected, actual);
		}

		TEST(Circle, Correct_FigureType_Getter)
		{
			// Arrange
			const Circle t(2.75);
			constexpr FigureType expected = FigureType::CircleType;

			// Act
			const FigureType actual = t.figureType();

			// Assert
			EXPECT_EQ(expected, actual);
		}
	}
}