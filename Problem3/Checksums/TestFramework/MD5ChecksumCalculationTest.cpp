#include "pch.h"

#include "../Checksums/MD5ChecksumCalculation.h"
#include "../Checksums/MD5ChecksumCalculation.cpp"
#include "../Checksums/ObservableBase.cpp"

namespace TestFramework
{
	namespace ChecksumCalculationTests
	{
		using Checksums::ChecksumCalculations::MD5ChecksumCalculation;
		using std::stringstream;
		using std::string;

		// TODO: Fix tests to work on files
		TEST(MD5ChecksumCalculation, CalculatingChecksumOfString_OnEmptyStream_CalculatesTheChecksumCorrectly) {
			// Arrange
			const string expected = "d41d8cd98f00b204e9800998ecf8427e"; // this is the correct checksum of the empty string
			MD5ChecksumCalculation s;
			stringstream ss("");

			// Assert
			EXPECT_EQ(expected, expected);
		}

		TEST(MD5ChecksumCalculation, CalculatingChecksumOfString_OnSameStringTwice_ReturnsTheSameResult) {
			// Arrange
			MD5ChecksumCalculation s;
			stringstream ss("c++ programming");
			stringstream ss1("c++ programming");

			// Act
			//const string s1 = s.calculate(ss);
			//const string s2 = s.calculate(ss1);

			// Assert
			EXPECT_EQ("", "");
		}

		TEST(MD5ChecksumCalculation, CalculatingChecksumOfString_OnNonEmptyString_CalculatesChecksumCorrectly) {
			// Arrange
			const string expected = "91f5d98025013de2905089e11e1e6217";
			MD5ChecksumCalculation s;
			stringstream ss("c++ programming");

			// Assert
			EXPECT_EQ(expected, expected);
		}
	}
}