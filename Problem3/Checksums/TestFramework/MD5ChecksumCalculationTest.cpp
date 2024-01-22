#include "pch.h"

#include "../Checksums/MD5ChecksumCalculation.h"
#include "../Checksums/MD5ChecksumCalculation.cpp"

namespace TestFramework
{
	namespace ChecksumCalculationTests
	{
		using Checksums::ChecksumCalculations::MD5ChecksumCalculation;
		using std::stringstream;
		using std::string;

		TEST(MD5ChecksumCalculation, CalculatingChecksumOfString_OnEmptyStream_CalculatesTheChecksumCorrectly) {
			// Arrange
			const string expected = "d41d8cd98f00b204e9800998ecf8427e"; // this is the correct checksum of the empty string
			MD5ChecksumCalculation s;
			stringstream ss("");

			// Assert
			EXPECT_EQ(expected, s.calculate(ss));
		}

		TEST(MD5ChecksumCalculation, CalculatingChecksumOfString_OnNonEmptyString_CalculatesChecksumCorrectly) {
			// Arrange
			const string expected = "91f5d98025013de2905089e11e1e6217";
			MD5ChecksumCalculation s;
			stringstream ss("c++ programming");

			// Assert
			EXPECT_EQ(expected, s.calculate(ss));
		}
	}
}