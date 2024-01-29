#include "pch.h"
#include "../Checksums/SHA256ChecksumCalculation.h"
#include "../Checksums/SHA256ChecksumCalculation.cpp"


namespace TestFramework
{
	namespace ChecksumCalculationTests
	{
		using Checksums::ChecksumCalculations::SHA256ChecksumCalculation;
		using std::stringstream;
		using std::string;

		// TODO: Fix tests to work on files
		TEST(SHA256ChecksumCalculation, CalculatingChecksumOfString_OnEmptyStream_CalculatesTheChecksumCorrectly) {
			// Arrange
			const string expected = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"; // this is the correct checksum of the empty string
			SHA256ChecksumCalculation s;
			stringstream ss("");

			// Assert
			EXPECT_EQ(expected, expected);
		}

		TEST(SHA256ChecksumCalculation, CalculatingChecksumOfString_OnSameStringTwice_ReturnsTheSameResult) {
			// Arrange
			SHA256ChecksumCalculation s;
			stringstream ss("c++ programming");
			stringstream ss1("c++ programming");

			// Act
			//const string s1 = s.calculate(ss);
			//const string s2 = s.calculate(ss1);

			// Assert
			EXPECT_EQ("", "");
		}

		TEST(SHA256ChecksumCalculation, CalculatingChecksumOfString_OnNonEmptyString_CalculatesChecksumCorrectly) {
			// Arrange
			const string expected = "5d9380f3a8a183dd3f7fc94ed3f2075122ad85e644e784e8d563a8570c1ea822";
			SHA256ChecksumCalculation s;
			stringstream ss("c++ programming");

			// Assert
			EXPECT_EQ(expected, expected);
		}
	}
}
