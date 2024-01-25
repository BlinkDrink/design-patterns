#include <filesystem>
#include<iostream>
#include<sstream>

#include "MD5ChecksumCalculation.h"
#include "NoFollowLinksBuilder.h"
#include "SHA256ChecksumCalculation.h"

namespace fs = std::filesystem;

int main()
{
	const Checksums::ChecksumCalculations::SHA256ChecksumCalculation md5;
	std::stringstream ss("Hello world!");
	std::cout << md5.calculate(ss);

	Checksums::Builders::NoFollowLinksBuilder nflb;
	const fs::path currentPath = fs::current_path();
	const fs::path fullPath = currentPath / "mock_directory1" / "mock_directory3";
	nflb.build(fullPath.string());

	std::cout << "Current Working Directory: " << currentPath << "\n";
	return 0;
}
