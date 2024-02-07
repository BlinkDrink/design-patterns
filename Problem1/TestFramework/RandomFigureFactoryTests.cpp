#include "pch.h"

#include <corecrt_math_defines.h>
#include <random>

#include "../Problem1/Circle.h"
#include "../Problem1/RandomFigureFactory.h"
#include "../Problem1/RandomFigureFactory.cpp"
#include "../Problem1/Rectangle.h"
#include "../Problem1/Triangle.h"


namespace TestFramework
{
	using std::make_unique;
	using std::stringstream;
	using std::invalid_argument;
	using Problem1::Figures::Circle;
	using Problem1::Figures::Figure;
	using std::default_random_engine;
	using Problem1::Figures::Triangle;
	using Problem1::Figures::Rectangle;
	using std::uniform_real_distribution;
	using Problem1::Factories::RandomFigureFactory;

	namespace RandomFigureFactoryTests
	{
		constexpr double lower_bound = DBL_EPSILON, upper_bound = 100, incorrect_case = -5;
		constexpr long long seed = 123;
		constexpr size_t iterations = 10;

		class RandomFigureFactoryTest : public ::testing::Test {
		protected:
			void SetUp() override {
				factory = RandomFigureFactory(lower_bound, upper_bound, seed);
			}

			RandomFigureFactory factory;
		};

		TEST_F(RandomFigureFactoryTest, Generate_Within_Bounds) {
			// Arrange
			const unique_ptr<Figure> figure = factory.create_figure();

			// Act
			EXPECT_GE(figure->perimeter(), lower_bound);
			EXPECT_LE(figure->perimeter(), 2 * M_PI * upper_bound); // Questionable test
		}

		TEST_F(RandomFigureFactoryTest, Generate_Same_Sequence_With_Same_Seed) {
			// Arrange
			RandomFigureFactory rff(lower_bound, upper_bound, seed);

			// Act
			RandomFigureFactory rff_same_seed(lower_bound, upper_bound, seed);

			// Assert
			for (int i = 0; i < iterations; ++i) {
				const unique_ptr<Figure> expected = rff.create_figure();
				const unique_ptr<Figure> actual = rff_same_seed.create_figure();

				EXPECT_EQ(*expected, *actual);
			}
		}

		TEST_F(RandomFigureFactoryTest, Generate_Different_Sequence_With_Different_Seed) {
			// Arrange
			RandomFigureFactory rff(lower_bound, upper_bound, seed);
			RandomFigureFactory rff_same_seed(lower_bound, upper_bound, seed + 1);

			// Assert
			for (int i = 0; i < iterations; ++i) {
				const unique_ptr<Figure> expected = rff.create_figure();
				const unique_ptr<Figure> actual = rff_same_seed.create_figure();
				bool check = *expected == *actual;

				EXPECT_EQ(check, false);
			}
		}

		TEST(RandomFigureFactory, Constructor_Throws_Incorrect_Input_Arguments)
		{
			// Assert
			EXPECT_THROW(RandomFigureFactory(incorrect_case, upper_bound, seed), invalid_argument);
			EXPECT_THROW(RandomFigureFactory(-lower_bound, incorrect_case, seed), invalid_argument);
			EXPECT_THROW(RandomFigureFactory(upper_bound, lower_bound, seed), invalid_argument);
		}
	}
}
