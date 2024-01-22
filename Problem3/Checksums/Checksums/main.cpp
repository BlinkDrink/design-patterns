#include<iostream>
#include<sstream>

#include "MD5ChecksumCalculation.h"
#include "SHA256ChecksumCalculation.h"

int main()
{
	const Checksums::ChecksumCalculations::SHA256ChecksumCalculation md5;
	std::stringstream ss("Hello world!");
	std::cout << md5.calculate(ss);
	return 0;
}
