#include <filesystem>
#include<iostream>
#include<sstream>

#include "FollowLinksBuilder.h"
#include "NoFollowLinksBuilder.h"
#include "SHA256ChecksumCalculation.h"

namespace fs = std::filesystem;

int main()
{
	//const Checksums::ChecksumCalculations::SHA256ChecksumCalculation md5;
	//std::stringstream ss("Hello world!");
	//std::cout << md5.calculate(ss);

	Checksums::Builders::NoFollowLinksBuilder nf;
	Checksums::Builders::FollowLinksBuilder f;
	const fs::path currentPath = fs::current_path();
	const fs::path fullPath = currentPath / "mock_directory1" / "mock_directory2";
	nf.build(fullPath.string());
	auto res = nf.getResult();
	std::cout << res->toString();
	return 0;
}
