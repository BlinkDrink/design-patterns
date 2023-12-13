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
	using Problem2::TextTransformations::LeftTrimTransformation;
	using Problem2::TextTransformations::RightTrimTransformation;
	using Problem2::TextTransformations::DecorateTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::NormalizeSpaceTransformation;
	using Problem2::TextTransformations::CensorTransformation;
	using Problem2::TextTransformations::TextTransformation;
	using Problem2::Labels::Label;
	using Problem2::Labels::SimpleLabel;

	namespace DecoratorTests
	{
		class RotatingTransformationDecoratorTest : public ::testing::Test {
		protected:
			unique_ptr<Label> label;
			vector<unique_ptr<TextTransformation>> transformations;
			vector<string> expectedValues;
			string base_text = "some  text";

			void SetUp() override {
				label = make_unique<SimpleLabel>(base_text);
				transformations.push_back(make_unique<CapitalizeTransformation>());
				transformations.push_back(make_unique<ReplaceTransformation>("so", "aweso"));
				transformations.push_back(make_unique<DecorateTransformation>());
				transformations.push_back(make_unique<ReplaceTransformation>("aweso", "so"));
				transformations.push_back(make_unique<CensorTransformation>("so"));
				transformations.push_back(make_unique<NormalizeSpaceTransformation>());

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

		TEST_F(RotatingTransformationDecoratorTest, Apply_One_Transformation_Correctly) {
			// Arrange
			const RotatingTransformationDecorator decorator(label, transformations);

			// Act
			string actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expectedValues[0]);
		}

		TEST_F(RotatingTransformationDecoratorTest, Apply_Two_Consecutive_Transformations_Correctly) {
			// Arrange
			const RotatingTransformationDecorator decorator(label, transformations);

			// Act
			string actual = decorator.getText();
			actual = decorator.getText();

			// Assert
			EXPECT_EQ(actual, expectedValues[1]);
		}

		TEST_F(RotatingTransformationDecoratorTest, Apply_ArbitraryNumberOfTimes_Yields_Correct_Result) {
			// Arrange
			const RotatingTransformationDecorator decorator(label, transformations);

			// Assert
			for (int i = 0; i < transformations.size(); ++i)
			{
				const string actual = decorator.getText();
				EXPECT_EQ(actual, expectedValues[i]);
			}
		}
	}
}
