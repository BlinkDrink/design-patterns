#include "pch.h"

#include "../Problem2/CensorTransformation.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/LabelFactory.h"
#include "../Problem2/LabelFactory.cpp"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/RotatingTransformationDecorator.h"
#include "../Problem2/SimpleLabel.h"
#include "../Problem2/TextTransformation.h"
#include "../Problem2/TextTransformationDecorator.h"

namespace TestFramework
{
	using Problem2::Factories::LabelFactory;
	using Problem2::TextTransformations::CensorTransformation;
	using Problem2::Labels::Label;

	using std::shared_ptr;
	using std::unique_ptr;
	using std::vector;

	namespace Factories
	{
		const string expected = "somecooltext";

		TEST(LabelFactory, CreateLabel_WithInvalidLabelTypeInput_ThrowsInvalidArgumentException)
		{
			// Assert
			EXPECT_THROW(LabelFactory::getInstance().create_label("none");, std::invalid_argument);
		}

		TEST(LabelFactory, CreateLabel_WithSimpleLabelInput_CreatesSimpleLabelCorrectly)
		{
			// Arrange
			unique_ptr<Label> l = LabelFactory::getInstance().create_label("simple " + expected);

			// Act
			string actual = l->getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST(LabelFactory, CreateLabel_WithInvalidArgumentInput_ThrowsInvalidArgumentException)
		{
			// Assert
			EXPECT_THROW(LabelFactory::getInstance().create_label("simple"); , std::invalid_argument);
		}

		TEST(LabelFactory, CreateLabel_WithRichLabelInput_CreatesRichLabelCorrectly)
		{
			// Arrange
			unique_ptr<Label> l = LabelFactory::getInstance().create_label("rich " + expected + " font_name font_color 15");

			// Act
			string actual = l->getText();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		TEST(LabelFactory, CreateLabel_WithProxyLabelInput_CreatesProxyLabelCorrectly)
		{
			// Arrange
			unique_ptr<Label> l = LabelFactory::getInstance().create_label("proxy 10");
			Problem2::Labels::ProxyLabel pl(10);

			// Assert
			EXPECT_EQ(pl, *l);
		}

		TEST(LabelFactory, AddHelpText_ToAnyLabel_ReturnsHelpLabelCorrectly)
		{
			// Arrange
			unique_ptr<Label> l = LabelFactory::getInstance().create_label("simple " + expected);
			const string help_message = "help_message";
			unique_ptr<Problem2::Labels::HelpLabel> hl = LabelFactory::getInstance().add_help_text_to(std::move(l), help_message);

			// Assert
			EXPECT_EQ(hl->getHelpText(), help_message);
		}

		TEST(LabelFactory, AddTextTransformationDecorator_ToAnyLabel_CorrectlyAttachesIt)
		{
			// Arrange
			const string expected_with_decorator = "Somecooltext";
			unique_ptr<Label> l = LabelFactory::getInstance().create_label("simple " + expected);
			l = LabelFactory::getInstance().add_text_decorator_to(std::move(l), std::make_unique<Problem2::TextTransformations::CapitalizeTransformation>());

			// Assert
			EXPECT_EQ(l->getText(), expected_with_decorator);
		}

		TEST(LabelFactory, AddRandomTransformationDecorator_ToAnyLabel_CorrectlyAttachesIt)
		{
			// Arrange
			const string expected_with_decorator = "s*mec**ltext";
			unique_ptr<Label> l = LabelFactory::getInstance().create_label("simple " + expected);
			vector<shared_ptr<Problem2::TextTransformations::TextTransformation>> tt{ std::make_unique<CensorTransformation>("o") };
			l = LabelFactory::getInstance().add_random_decorator_to(std::move(l), tt, 123);

			// Assert
			EXPECT_EQ(l->getText(), expected_with_decorator);
		}

		TEST(LabelFactory, AddRotatingTransformationDecorator_ToAnyLabel_CorrectlyAttachesIt)
		{
			// Arrange
			const string expected_with_decorator1 = "s*mec**ltext";
			const string expected_with_decorator2 = "somecooltext";
			unique_ptr<Label> l = LabelFactory::getInstance().create_label("simple " + expected);
			vector<shared_ptr<Problem2::TextTransformations::TextTransformation>> tt{ std::make_unique<CensorTransformation>("o"), std::make_unique<Problem2::TextTransformations::ReplaceTransformation>("*","o") };
			l = LabelFactory::getInstance().add_rotating_decorator_to(std::move(l), tt);

			// Assert
			EXPECT_EQ(l->getText(), expected_with_decorator1);
			EXPECT_EQ(l->getText(), expected_with_decorator2);
		}
	}
}
