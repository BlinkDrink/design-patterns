#include "pch.h"

#include "../Problem2/ProxyLabel.h"
#include "../Problem2/ProxyLabel.cpp"

namespace TestFramework
{
	using Problem2::Labels::ProxyLabel;
	using std::stringstream;

	namespace LabelTests
	{
		using std::istringstream;
		using std::cin;

		constexpr int timeout = 5;
		constexpr int invalid_timeout = -5;

		TEST(ProxyLabel, Constructor_ThrowsInvalidArgumentException_With_NonPositiveTimeoutValue) {
			// Assert
			EXPECT_THROW(ProxyLabel p(invalid_timeout), std::invalid_argument);
		}

		TEST(ProxyLabel, FirstCallOfgetText_SetsInnerLabelText_Correctly) {
			// Arrange
			const string expected = "some text";
			const ProxyLabel pl1(timeout);
			const istringstream input_stream("some text");
			cin.rdbuf(input_stream.rdbuf());

			// Act
			const string actual = pl1.getText();

			// Assert
			EXPECT_EQ(expected, actual);
		}

		TEST(ProxyLabel, Comparison_BetweenEqualProxyLabels_ReturnsTrue) {
			// Arrange
			const ProxyLabel pl1(timeout);
			const ProxyLabel pl2(timeout);
			istringstream input_stream("some text");
			cin.rdbuf(input_stream.rdbuf());

			// Act
			string text1 = pl1.getText();
			input_stream = istringstream("some text");
			cin.rdbuf(input_stream.rdbuf());
			string text2 = pl2.getText();

			// Assert
			EXPECT_EQ(pl1, pl2);
		}

		TEST(ProxyLabel, AfterTimeout_GivingInputYes_CorrectlySetsInnerLabelText) {
			// Arrange
			const string expected = "new text";
			const ProxyLabel pl1(timeout);
			istringstream input_stream("some text");
			cin.rdbuf(input_stream.rdbuf());

			// Act
			string actual = pl1.getText();
			for (int i = 0; i < timeout - 2; ++i)
			{
				actual = pl1.getText();
			}

			input_stream = istringstream("y new text");
			cin.rdbuf(input_stream.rdbuf());
			actual = pl1.getText();

			// Assert
			EXPECT_EQ(expected, actual);
		}

		TEST(ProxyLabel, AfterTimeout_GivingInputNo_LeavesTheLabelUnchanged) {
			// Arrange
			const string expected = "some text";
			const ProxyLabel pl1(timeout);
			istringstream input_stream("some text");
			cin.rdbuf(input_stream.rdbuf());

			// Act
			string actual = pl1.getText();
			for (int i = 0; i < timeout - 2; ++i)
			{
				actual = pl1.getText();
			}

			input_stream = istringstream("n");
			cin.rdbuf(input_stream.rdbuf());
			actual = pl1.getText();

			// Assert
			EXPECT_EQ(expected, actual);
		}

		TEST(ProxyLabel, Comparison_OfProxyLabel_WithItself_ReturnsTrue) {
			// Arrange
			const ProxyLabel s(timeout);

			// Assert
			EXPECT_EQ(s, s);
		}
	}
}
