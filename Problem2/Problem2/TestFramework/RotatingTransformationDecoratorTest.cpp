#include "pch.h"

#include "../Problem2/CapitalizeTransformation.h"
#include "../Problem2/CensorTransformation.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/LeftTrimTransformation.h"
#include "../Problem2/NormalizeSpaceTransformation.h"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/RightTrimTransformation.h"
#include "../Problem2/RotatingTransformationDecorator.h"
#include "../Problem2/SimpleLabel.h"
#include "../Problem2/RotatingTransformationDecorator.cpp"

namespace TestFramework
{
	using std::unique_ptr;
	using std::vector;
	using std::make_unique;
	using Problem2::Decorators::RotatingTransformationDecorator;
	using Problem2::TextTransformations::CapitalizeTransformation;
	using Problem2::TextTransformations::DecorateTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::NormalizeSpaceTransformation;
	using Problem2::TextTransformations::CensorTransformation;
	using Problem2::TextTransformations::TextTransformation;
	using Problem2::Labels::Label;
	using Problem2::Labels::SimpleLabel;
	using std::shared_ptr;
	using std::make_shared;

	namespace DecoratorTests
	{
		class RotatingTransformationDecoratorTest : public ::testing::Test {
		protected:
			unique_ptr<Label> label;
			vector<shared_ptr<TextTransformation>> transformations;
			vector<shared_ptr<TextTransformation>> emptyTransformations;
			vector<string> expectedValues;
			string base_text = "some  text";
			const int iterations = 100;

			void SetUp() override {
				label = make_unique<SimpleLabel>(base_text);
				transformations.push_back(make_shared<CapitalizeTransformation>());
				transformations.push_back(make_shared<ReplaceTransformation>("so", "aweso"));
				transformations.push_back(make_shared<DecorateTransformation>());
				transformations.push_back(make_shared<ReplaceTransformation>("aweso", "so"));
				transformations.push_back(make_shared<CensorTransformation>("so"));
				transformations.push_back(make_shared<NormalizeSpaceTransformation>());

				expectedValues.push_back("Some  text");
				expectedValues.push_back("awesome  text");
				expectedValues.push_back("-={ some  text }=-");
				expectedValues.push_back("some  text");
				expectedValues.push_back("**me  text");
				expectedValues.push_back("some text");
			}

			void TearDown() override {

			}
		};

		TEST_F(RotatingTransformationDecoratorTest, Constructor_ThrowsInvalidArgumentException_WithEmptyListOfTransformations) {
			// Assert
			EXPECT_THROW(RotatingTransformationDecorator decorator2(make_unique<SimpleLabel>("something"), emptyTransformations), std::invalid_argument);
		}

		TEST_F(RotatingTransformationDecoratorTest, ComparisonBetweenRotatingTransformationDecorators_WithSameTransformations_ReturnsTrue) {
			// Arrange
			vector<shared_ptr<TextTransformation>> transformations2;
			transformations2.push_back(make_shared<CapitalizeTransformation>());
			transformations2.push_back(make_shared<ReplaceTransformation>("so", "aweso"));
			transformations2.push_back(make_shared<DecorateTransformation>());
			transformations2.push_back(make_shared<ReplaceTransformation>("aweso", "so"));
			transformations2.push_back(make_shared<CensorTransformation>("so"));
			transformations2.push_back(make_shared<NormalizeSpaceTransformation>());
			RotatingTransformationDecorator decorator(std::move(label), transformations);
			RotatingTransformationDecorator decorator2(make_unique<SimpleLabel>("something"), transformations2);

			// Assert
			EXPECT_EQ(decorator, decorator2);
		}

		TEST_F(RotatingTransformationDecoratorTest, ComparisonBetween_RotatingTransformationDecorators_WithDifferentTransformations_ReturnsFalse) {
			// Arrange
			vector<shared_ptr<TextTransformation>> transformations2;
			transformations2.push_back(make_shared<CapitalizeTransformation>());
			transformations2.push_back(make_shared<ReplaceTransformation>("so", "aweso"));
			transformations2.push_back(make_shared<CensorTransformation>("so"));
			transformations2.push_back(make_shared<NormalizeSpaceTransformation>());
			const RotatingTransformationDecorator decorator(std::move(label), transformations);
			const RotatingTransformationDecorator decorator2(make_unique<SimpleLabel>("something"), transformations2);

			// Act
			const bool check = decorator == decorator2;

			// Assert
			EXPECT_FALSE(check);
		}

		TEST_F(RotatingTransformationDecoratorTest, Apply_One_Transformation_ReturnsCorrectResult) {
			// Arrange
			const RotatingTransformationDecorator decorator(std::move(label), transformations);

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expectedValues[0]);
		}

		TEST_F(RotatingTransformationDecoratorTest, Apply_Two_Consecutive_Transformations_ReturnsCorrectResult) {
			// Arrange
			const RotatingTransformationDecorator decorator(std::move(label), transformations);

			// Act
			string actual = decorator.getText();
			actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expectedValues[1]);
		}

		TEST_F(RotatingTransformationDecoratorTest, Apply_ArbitraryNumberOfTimes_Yields_Correct_Result) {
			// Arrange
			const RotatingTransformationDecorator decorator(std::move(label), transformations);

			// Assert
			for (int i = 0; i < iterations; ++i)
			{
				const string actual = decorator.getText();
				EXPECT_EQ(actual, expectedValues[i % transformations.size()]);
			}
		}
	}
}
