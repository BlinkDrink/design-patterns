#include <filesystem>
#include<iostream>
#include<sstream>

#include "FollowLinksBuilder.h"
#include "NoFollowLinksBuilder.h"
#include "ReportWriter.h"
#include "Directory.h"
#include "HashStreamWriter.h"
#include "MD5ChecksumCalculation.h"
#include "SHA256ChecksumCalculation.h"

namespace fs = std::filesystem;

int main()
{
	std::unique_ptr<Checksums::ChecksumCalculations::ChecksumCalculationBase> md5 = std::make_unique<Checksums::ChecksumCalculations::MD5ChecksumCalculation>();

	Checksums::Builders::NoFollowLinksBuilder nf;
	Checksums::Builders::FollowLinksBuilder f;
	const fs::path currentPath = fs::current_path();

	const fs::path fullPath = currentPath / "mock_directory1" /*/ "mock_directory2"*/;
	auto relativePath = fs::relative(fs::absolute(fullPath));
	auto absPath = fs::absolute(relativePath);
	f.build(fullPath.string());
	std::unique_ptr<Checksums::TreeElements::FileTreeElement> res = f.getResult();
	Checksums::Visitors::HashStreamWriter rwv(std::cout, std::move(md5));
	res->accept(rwv);

	return 0;
}
