#include "pch.h"
#include "../Problem2/SimpleLabel.h"
#include "../Problem2/SimpleLabel.cpp"

namespace TestFramework
{
	using Problem2::Labels::SimpleLabel;

	namespace LabelTests
	{
		const string expected = "value";

		TEST(SimpleLabelTest, Correct_Return_Of_Value) {
			// Arrange
			const SimpleLabel s(expected);

			// Assert
			EXPECT_EQ(expected, s.getText());
		}
	}
}
