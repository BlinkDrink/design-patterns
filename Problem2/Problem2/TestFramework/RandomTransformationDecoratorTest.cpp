#include "pch.h"

#include "../Problem2/CapitalizeTransformation.h"
#include "../Problem2/CensorTransformation.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/NormalizeSpaceTransformation.h"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/LabelDecoratorBase.h"
#include "../Problem2/SimpleLabel.h"
#include "../Problem2/RandomTransformationDecorator.h"
#include "../Problem2/RandomTransformationDecorator.cpp"
#include "../Problem2/LabelDecoratorBase.cpp"
#include "../Problem2/RotatingTransformationDecorator.h"
#include "../Problem2/TextTransformationDecorator.h"

namespace TestFramework
{
	using std::unique_ptr;
	using std::vector;
	using std::shared_ptr;
	using std::make_unique;
	using std::make_shared;
	using Problem2::Labels::Label;
	using Problem2::Labels::SimpleLabel;
	using Problem2::Decorators::RandomTransformationDecorator;
	using Problem2::TextTransformations::CapitalizeTransformation;
	using Problem2::TextTransformations::DecorateTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::NormalizeSpaceTransformation;
	using Problem2::TextTransformations::CensorTransformation;
	using Problem2::TextTransformations::TextTransformation;
	using Problem2::Decorators::TextTransformationDecorator;
	using Problem2::Decorators::RotatingTransformationDecorator;

	namespace DecoratorTests
	{
		constexpr long long seed = 123;
		constexpr size_t iterations = 50;
		const string base_text = "some  text";

		class RandomTransformationDecoratorTest : public ::testing::Test
		{
		protected:
			unique_ptr<Label> label1;
			unique_ptr<Label> label2;
			vector<shared_ptr<TextTransformation>> transformations1;
			vector<shared_ptr<TextTransformation>> transformations2;
			vector<string> expectedValues;
			vector<shared_ptr<TextTransformation>> emptyVector;

			void SetUp() override
			{
				label1 = make_unique<SimpleLabel>(base_text);
				label2 = make_unique<SimpleLabel>(base_text);
				transformations1.push_back(make_shared<CapitalizeTransformation>());
				transformations1.push_back(make_shared<ReplaceTransformation>("so", "aweso"));
				transformations1.push_back(make_shared<DecorateTransformation>());
				transformations1.push_back(make_shared<ReplaceTransformation>("aweso", "so"));
				transformations1.push_back(make_shared<CensorTransformation>("so"));
				transformations1.push_back(make_shared<NormalizeSpaceTransformation>());

				transformations2.push_back(make_shared<DecorateTransformation>());
				transformations2.push_back(make_shared<NormalizeSpaceTransformation>());

				expectedValues.push_back("Some  text");
				expectedValues.push_back("awesome  text");
				expectedValues.push_back("-={ some  text }=-");
				expectedValues.push_back("some  text");
				expectedValues.push_back("**me  text");
				expectedValues.push_back("some text");
			}

			void TearDown() override
			{

			}
		};

		TEST_F(RandomTransformationDecoratorTest, GenerateSameSequence_With_SameSeed)
		{
			// Arrange
			const RandomTransformationDecorator decorator1(std::move(label1), transformations1, seed);
			const RandomTransformationDecorator decorator2(std::move(label2), transformations1, seed);

			// Assert
			for (size_t i = 0; i < iterations; ++i)
			{
				EXPECT_EQ(decorator1.getText(), decorator2.getText());
			}
		}

		TEST_F(RandomTransformationDecoratorTest, AppliedTransformations_Are_InGivenBoundsOfExpectedValues)
		{
			// Arrange
			const RandomTransformationDecorator decorator1(std::move(label1), transformations1, seed);

			// Assert
			for (size_t i = 0; i < iterations; ++i)
			{
				const string text = decorator1.getText();
				bool check = false;

				for (size_t j = 0; j < expectedValues.size(); ++j)
				{
					check = check || text == expectedValues[j];
					if (check)
						break;
				}

				EXPECT_TRUE(check);
			}
		}

		TEST_F(RandomTransformationDecoratorTest, AppliedTransformation_AfterRemovalOfChainedDecorator_IsInGivenBoundsOfExpectedValues)
		{
			// Arrange
			const TextTransformationDecorator toRemove(std::move(label2), transformations1[2]);
			unique_ptr<Label> decorator1 = make_unique<RandomTransformationDecorator>(std::move(label1), transformations1, seed);
			decorator1 = make_unique<TextTransformationDecorator>(std::move(decorator1), transformations1[2]);
			decorator1 = Problem2::Decorators::LabelDecoratorBase::removeDecoratorFrom(std::move(decorator1), toRemove);

			// Assert
			for (size_t i = 0; i < iterations; ++i)
			{
				const string text = decorator1->getText();
				bool check = false;

				for (size_t j = 0; j < expectedValues.size(); ++j)
				{
					check = check || text == expectedValues[j];
					if (check)
						break;
				}

				EXPECT_TRUE(check);
			}
		}

		TEST_F(RandomTransformationDecoratorTest, ConstructorThrows_InvalidArgumentException__With_EmptyTransformationsList)
		{
			// Act
			EXPECT_THROW(RandomTransformationDecorator decorator1(std::move(label1), emptyVector, seed), std::invalid_argument);
		}
	}
}
