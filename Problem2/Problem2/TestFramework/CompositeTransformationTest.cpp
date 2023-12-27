#include "pch.h"

#include "../Problem2/CapitalizeTransformation.h"
#include "../Problem2/CensorTransformation.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/CompositeTransformation.h"
#include "../Problem2/CompositeTransformation.cpp"
#include "../Problem2/NormalizeSpaceTransformation.h"
#include "../Problem2/ReplaceTransformation.h"

namespace TestFramework
{
	using std::vector;
	using std::unique_ptr;
	using std::shared_ptr;
	using std::make_unique;
	using std::make_shared;
	using Problem2::Labels::Label;
	using Problem2::TextTransformations::CompositeTransformation;
	using Problem2::TextTransformations::TextTransformation;
	using Problem2::TextTransformations::DecorateTransformation;
	using Problem2::TextTransformations::ReplaceTransformation;
	using Problem2::TextTransformations::CapitalizeTransformation;
	using Problem2::TextTransformations::CensorTransformation;
	using Problem2::TextTransformations::NormalizeSpaceTransformation;

	namespace TextTransformationTests
	{
		const string input = "some text";

		class CompositeTransformationTest : public ::testing::Test
		{
		protected:
			vector<shared_ptr<TextTransformation>> transformations1;
			shared_ptr<TextTransformation> tt;

			void SetUp() override
			{
				transformations1.push_back(make_shared<CapitalizeTransformation>());
				transformations1.push_back(make_shared<ReplaceTransformation>("so", "aweso"));
				transformations1.push_back(make_shared<DecorateTransformation>());
				transformations1.push_back(make_shared<ReplaceTransformation>("e", "o"));
				transformations1.push_back(make_shared<CensorTransformation>("so"));
				transformations1.push_back(make_shared<NormalizeSpaceTransformation>());
				tt = make_shared<CompositeTransformation>();
			}

			void TearDown() override
			{

			}
		};

		TEST_F(CompositeTransformationTest, ApplyTransformation_OneLevelComposite_ReturnsCorrectResult)
		{
			// Arrange
			const string expected = "-={ Some text }=-";
			CompositeTransformation s;
			s.add(transformations1[0]);
			s.add(transformations1[1]);
			s.add(transformations1[2]);

			// act
			string test = s.transform(input);

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}

		TEST_F(CompositeTransformationTest, ApplyTransformation_MultiLevelComposite_ReturnsCorrectResult)
		{
			// Arrange
			const string expected = "-={ Somo toxt }=-";
			CompositeTransformation s;
			s.add(transformations1[0]);
			tt->add(transformations1[1]);
			tt->add(transformations1[3]);
			s.add(tt);
			s.add(transformations1[2]);

			// Assert
			EXPECT_EQ(expected, s.transform(input));
		}

		TEST_F(CompositeTransformationTest, Comparison_Of_DifferentCompositeTransformations_ReturnFalse)
		{
			// Arrange
			CompositeTransformation s1;
			CompositeTransformation s2;
			s1.add(transformations1[0]);
			tt->add(transformations1[1]);
			tt->add(transformations1[3]);
			s1.add(tt);
			s1.add(transformations1[2]);

			s2.add(tt);
			s2.add(transformations1[4]);
			s2.add(transformations1[5]);

			// Act
			const bool check = s1 == s2;

			// Assert
			EXPECT_FALSE(check);
		}
	}
}
