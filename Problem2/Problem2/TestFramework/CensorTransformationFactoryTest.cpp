#include "pch.h"

#include "../Problem2/CensorTransformation.h"
#include "../Problem2/DecorateTransformation.h"
#include "../Problem2/CensorTransformationFactory.h"
#include "../Problem2/CensorTransformationFactory.cpp"
#include "../Problem2/ReplaceTransformation.h"
#include "../Problem2/RotatingTransformationDecorator.h"
#include "../Problem2/SimpleLabel.h"
#include "../Problem2/TextTransformation.h"
#include "../Problem2/TextTransformationDecorator.h"

namespace TestFramework
{
	using Problem2::Factories::CensorTransformationFactory;
	using Problem2::TextTransformations::CensorTransformation;

	using std::shared_ptr;
	using std::vector;

	namespace Factories
	{
		vector<string> getAllPermutations(const string& str)
		{
			vector<string> permutations;
			string temp = str;
			sort(temp.begin(), temp.end());

			do
			{
				permutations.push_back(temp);
			} while (next_permutation(temp.begin(), temp.end()));

			return permutations;
		}

		TEST(CensorTransformationFactory, CreationOfCensor_UnderFiveLetters_GetsStoredAndReused) {
			// Arrange
			const vector<vector<string>> values{ {"a"}, getAllPermutations("ab"), getAllPermutations("abc"), getAllPermutations("abcd") };
			CensorTransformationFactory ctf;

			for (size_t i = 0; i < values.size(); ++i)
			{
				for (size_t j = 0; j < values[i].size(); ++j)
				{
					const shared_ptr<CensorTransformation> item1 = ctf.createCensorTransformation(values[i][j]);
					const shared_ptr<CensorTransformation> item2 = ctf.createCensorTransformation(values[i][j]);

					// Assert
					EXPECT_EQ(item1, item2);
				}
			}
		}

		TEST(CensorTransformationFactory, CreationOfCensor_OverFourLetters_GetsCreatedAnew_Everytime) {
			// Arrange
			CensorTransformationFactory ctf;

			// Act
			const shared_ptr<CensorTransformation> item1 = ctf.createCensorTransformation("abcde");
			const shared_ptr<CensorTransformation> item2 = ctf.createCensorTransformation("abcde");

			// Assert
			EXPECT_NE(item1, item2);
		}
	}
}
