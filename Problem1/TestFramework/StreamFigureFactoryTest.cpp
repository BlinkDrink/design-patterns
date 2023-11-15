#include "pch.h"
#include "../problem1/StreamFigureFactory.h"
#include "../problem1/StreamFigureFactory.cpp"

using Problem1::Factories::StreamFigureFactory;
using std::stringstream;

namespace TestFramework
{
	namespace StreamFigureFactoryTests
	{
		TEST(StreamFigureFactory, Correct_Rectangle_Reading_From_Stream)
		{
			// Arrange
			stringstream ss("rectangle 3 4");
			StreamFigureFactory sff(ss);
			const string expected = "rectangle 3 4";

			// Act
			const unique_ptr<Figure> f = sff.create_figure();

			// Assert
			EXPECT_EQ(expected, f->toString());
		}

		TEST(StreamFigureFactory, Correct_Circle_Reading_From_Stream)
		{
			// Arrange
			stringstream ss("circle 6.53");
			StreamFigureFactory sff(ss);
			const string expected = "circle 6.53";

			// Act
			const unique_ptr<Figure> f = sff.create_figure();

			// Assert
			EXPECT_EQ(expected, f->toString());
		}

		TEST(StreamFigureFactory, Correct_Triangle_Reading_From_Stream)
		{
			// Arrange
			stringstream ss("triangle 5 4 3");
			StreamFigureFactory sff(ss);
			const string expected = "triangle 3 4 5";

			// Act
			const unique_ptr<Figure> f = sff.create_figure();

			// Assert
			EXPECT_EQ(expected, f->toString());
		}

		TEST(StreamFigureFactory, Read_Multiple_Figures_From_Stream)
		{
			// Arrange
			stringstream ss("triangle 5 4 3\ncircle 2.88\nrectangle 55 33");
			StreamFigureFactory sff(ss);
			const string expected1 = "triangle 3 4 5";
			const string expected2 = "circle 2.88";
			const string expected3 = "rectangle 33 55";

			// Act
			const unique_ptr<Figure> f1 = sff.create_figure();
			const unique_ptr<Figure> f2 = sff.create_figure();
			const unique_ptr<Figure> f3 = sff.create_figure();

			// Assert
			EXPECT_EQ(expected1, f1->toString());
			EXPECT_EQ(expected2, f2->toString());
			EXPECT_EQ(expected3, f3->toString());
		}

		TEST(StreamFigureFactory, Throw_On_Invalid_Figure_Type_In_Beginning)
		{
			// Arrange
			stringstream ss("programming 5 4 3\ncircle 2.88\nrectangle 55 33");
			StreamFigureFactory sff(ss);

			// Assert
			EXPECT_THROW(sff.create_figure(), invalid_argument);
		}

		TEST(StreamFigureFactory, Throw_On_Invalid_Figure_Type_In_Middle)
		{
			// Arrange
			stringstream ss("triangle 5 4 3\nprogramming 2.88\nrectangle 55 33");
			StreamFigureFactory sff(ss);

			const unique_ptr<Figure> f1 = sff.create_figure();

			// Assert
			EXPECT_THROW(sff.create_figure(), invalid_argument);
		}

		TEST(StreamFigureFactory, Throw_On_Invalid_Triangle_Sides)
		{
			// Arrange
			stringstream ss("triangle 5 programming 3");
			StreamFigureFactory sff(ss);

			// Assert
			EXPECT_THROW(sff.create_figure(), invalid_argument);
		}

		TEST(StreamFigureFactory, Throw_On_Invalid_Circle_Radius)
		{
			// Arrange
			stringstream ss("circle programming");
			StreamFigureFactory sff(ss);

			// Assert
			EXPECT_THROW(sff.create_figure(), invalid_argument);
		}

		TEST(StreamFigureFactory, Throw_On_Invalid_Rectangle_Sides)
		{
			// Arrange
			stringstream ss("rectangle 3.14 programming");
			StreamFigureFactory sff(ss);

			// Assert
			EXPECT_THROW(sff.create_figure(), invalid_argument);
		}
	}
}
