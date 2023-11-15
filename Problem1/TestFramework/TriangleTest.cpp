#include "pch.h"

#include "Circle.h"
#include "Rectangle.h"
#include "../Problem1/Triangle.h"
#include "../Problem1/Triangle.cpp"
#include "../Problem1/Utils.cpp"

using Problem1::Figures::Triangle;
using Problem1::Figures::Figure;
using Problem1::Figures::Circle;

namespace TestFramework
{
	namespace TriangleTests
	{
		TEST(Triangle, Constructor_NoThrow_Correct_Triangle_Rule_Arguments)
		{
			// Assert
			EXPECT_NO_THROW(Triangle t(2.75, 3.25, 5));
		}

		TEST(Triangle, Constructor_Throw_False_Triangle_Rule_Arguments)
		{
			// Assert
			EXPECT_THROW(Triangle t(2.75, 3.25, 10), std::invalid_argument);
		}

		TEST(Triangle, Constructor_Throw_Non_Positive_Arguments)
		{
			// Assert
			EXPECT_THROW(Triangle t(-2.75, 3.25, 5), std::invalid_argument);
			EXPECT_THROW(Triangle t(2.75, -3.25, 5), std::invalid_argument);
			EXPECT_THROW(Triangle t(2.75, 3.25, -5), std::invalid_argument);
			EXPECT_THROW(Triangle t(2.75, 3.25, 0), std::invalid_argument);
			EXPECT_THROW(Triangle t(2.75, 0, 2), std::invalid_argument);
			EXPECT_THROW(Triangle t(0, 3.25, 5), std::invalid_argument);
		}

		TEST(Triangle, Constructor_Sorts_Field_Members)
		{
			// Arrange
			Triangle t(4, 3, 5);
			const string expected = "triangle 3 4 5";

			// Act
			const string stringified = t.toString();

			// Assert
			EXPECT_EQ(stringified, expected);
		}

		TEST(Triangle, Correct_Perimeter_Calculation)
		{
			// Arrange
			const Triangle t(2.75, 3.25, 5);
			constexpr double expected = 11;

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


		TEST(Triangle, Correct_Triangle_Comparison_With_Other_Figure)
		{
			// Arrange
			const Triangle t1(2.75, 3.25, 5);
			const Circle t2(2.75);
			constexpr bool expected = false;

			// Act
			const bool check = t1 == t2;

			// Assert
			EXPECT_EQ(check, expected);
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
			const Triangle t1(2.75, 3.25, 5);
			const string expected = t1.toString();

			// Act
			const unique_ptr<Figure> t2 = t1.clone();
			const string actual = t2->toString();

			// Assert
			EXPECT_EQ(expected, actual);
		}
	}
}


