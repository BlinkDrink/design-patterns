#include<iostream>
#include<sstream>

#include "MD5ChecksumCalculation.h"
#include "SHA2ChecksumCalculation.h"

int main()
{
	const Checksums::ChecksumCalculations::SHA2ChecksumCalculation md5;
	std::stringstream ss("Hello world!");
	std::cout << md5.calculate(ss);
	return 0;
}
