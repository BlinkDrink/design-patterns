#include "pch.h"
#include "../problem1/StreamFigureFactory.h"
#include "../problem1/StreamFigureFactory.cpp"

TEST(StreamFigureFactory, Correct_Rectangle_Reading_From_Stream)
{
	// Arrange
	std::stringstream ss("rectangle 3 4");
	const StreamFigureFactory sff(ss);
	const string expected = "rectangle 3 4";

	// Act
	const unique_ptr<Figure> f = sff.create_figure();

	// Assert
	EXPECT_EQ(expected, f->toString());
}

TEST(StreamFigureFactory, Correct_Circle_Reading_From_Stream)
{
	// Arrange
	std::stringstream ss("circle 6.53");
	const StreamFigureFactory sff(ss);
	const string expected = "circle 6.53";

	// Act
	const unique_ptr<Figure> f = sff.create_figure();

	// Assert
	EXPECT_EQ(expected, f->toString());
}

TEST(StreamFigureFactory, Correct_Triangle_Reading_From_Stream)
{
	// Arrange
	std::stringstream ss("triangle 5 4 3");
	const StreamFigureFactory sff(ss);
	const string expected = "triangle 3 4 5";

	// Act
	const unique_ptr<Figure> f = sff.create_figure();

	// Assert
	EXPECT_EQ(expected, f->toString());
}

TEST(StreamFigureFactory, Read_Multiple_Figures_From_Stream)
{
	// Arrange
	std::stringstream ss("triangle 5 4 3 circle 2.88 rectangle 55 33");
	const StreamFigureFactory sff(ss);
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