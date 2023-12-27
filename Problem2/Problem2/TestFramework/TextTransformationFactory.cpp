#include "pch.h"

#include "../Problem2/CensorTransformation.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/RotatingTransformationDecorator.h"
#include "../Problem2/CapitalizeTransformation.h"
#include "../Problem2/TextTransformationFactory.h"
#include "../Problem2/TextTransformationFactory.cpp"

namespace TestFramework
{
	using Problem2::Factories::TextTransformationFactory;
	using Problem2::Factories::CensorTransformationFactory;
	using Problem2::TextTransformations::CapitalizeTransformation;
	using Problem2::TextTransformations::CensorTransformation;
	using Problem2::TextTransformations::TextTransformation;
	using Problem2::TextTransformations::NormalizeSpaceTransformation;
	using Problem2::TextTransformations::LeftTrimTransformation;
	using Problem2::TextTransformations::RightTrimTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::DecorateTransformation;

	using std::shared_ptr;
	using std::vector;

	namespace Factories
	{
		TEST(TextTransformationFactory, Creation_WithCapitalizeInput_ReturnsCapitalizeTransformation) {
			// Arrange
			TextTransformationFactory ttf;
			const CapitalizeTransformation expected;
			string input = "capitalize";

			// Act
			shared_ptr<TextTransformation> actual = ttf.create_transformation(input);

			// Assert
			EXPECT_EQ(expected, *actual);
		}

		TEST(TextTransformationFactory, Creation_WithNormalizeSpacesInput_ReturnsNormalizeSpaceTransformation) {
			// Arrange
			TextTransformationFactory ttf;
			const NormalizeSpaceTransformation expected;
			string input = "normalize_spaces";

			// Act
			shared_ptr<TextTransformation> actual = ttf.create_transformation(input);

			// Assert
			EXPECT_EQ(expected, *actual);
		}

		TEST(TextTransformationFactory, Creation_WithLeftTrimInput_ReturnsLeftTrimTransformation) {
			// Arrange
			TextTransformationFactory ttf;
			const LeftTrimTransformation expected;
			string input = "left_trim";

			// Act
			shared_ptr<TextTransformation> actual = ttf.create_transformation(input);

			// Assert
			EXPECT_EQ(expected, *actual);
		}

		TEST(TextTransformationFactory, Creation_WithRightTrimInput_ReturnsRightTrimTransformation) {
			// Arrange
			TextTransformationFactory ttf;
			const RightTrimTransformation expected;
			string input = "right_trim";

			// Act
			shared_ptr<TextTransformation> actual = ttf.create_transformation(input);

			// Assert
			EXPECT_EQ(expected, *actual);
		}

		TEST(TextTransformationFactory, Creation_WithDecorateInput_ReturnsDecorateTransformation) {
			// Arrange
			TextTransformationFactory ttf;
			const DecorateTransformation expected;
			string input = "decorate";

			// Act
			shared_ptr<TextTransformation> actual = ttf.create_transformation(input);

			// Assert
			EXPECT_EQ(expected, *actual);
		}

		TEST(TextTransformationFactory, Creation_WithCensorInput_ReturnsCensorTransformation) {
			// Arrange
			TextTransformationFactory ttf;
			const CensorTransformation expected("o");
			string input = "censor o";

			// Act
			shared_ptr<TextTransformation> actual = ttf.create_transformation(input);

			// Assert
			EXPECT_EQ(expected, *actual);
		}

		TEST(TextTransformationFactory, Creation_WithReplaceInput_ReturnsReplaceTransformation) {
			// Arrange
			TextTransformationFactory ttf;
			const ReplaceTransformation expected("a", "b");
			string input = "replace a b";

			// Act
			shared_ptr<TextTransformation> actual = ttf.create_transformation(input);

			// Assert
			EXPECT_EQ(expected, *actual);
		}

		TEST(TextTransformationFactory, Creation_WithInvalidTransformationType_ThrowsInvalidArgumentException) {
			// Arrange
			TextTransformationFactory ttf;
			string input = "to_upper a b";

			// Assert
			EXPECT_THROW(ttf.create_transformation(input);, std::invalid_argument);
		}

		TEST(TextTransformationFactory, CreationOfReplaceTransformation_WithInsufficientArguments_ThrowsInvalidArgumentException) {
			// Arrange
			TextTransformationFactory ttf;
			string input = "replace a";

			// Assert
			EXPECT_THROW(ttf.create_transformation(input); , std::invalid_argument);
		}

		TEST(TextTransformationFactory, CreationOfCensorTransformation_WithInsufficientArguments_ThrowsInvalidArgumentException) {
			// Arrange
			TextTransformationFactory ttf;
			string input = "censor";

			// Assert
			EXPECT_THROW(ttf.create_transformation(input);, std::invalid_argument);
		}
	}
}
