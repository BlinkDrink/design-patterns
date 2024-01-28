#include <filesystem>
#include <memory>

#include "FollowLinksBuilder.h"
#include "NoFollowLinksBuilder.h"
#include "ReportWriter.h"
#include "HashStreamWriter.h"
#include "MD5ChecksumCalculation.h"
#include "ProgressReporter.h"

namespace fs = std::filesystem;

int main()
{
	std::unique_ptr<Checksums::ChecksumCalculations::ChecksumCalculationBase> md5 = std::make_unique<Checksums::ChecksumCalculations::MD5ChecksumCalculation>();

	Checksums::Builders::NoFollowLinksBuilder nf;
	Checksums::Builders::FollowLinksBuilder f;
	const fs::path currentPath = fs::current_path();
	const fs::path pathToPrint = currentPath / "checksums.txt";
	const fs::path fullPath = currentPath / "mock_directory1" /*/ "mock_directory2"*/;

	std::ofstream file(pathToPrint.string());
	auto relativePath = fs::relative(fs::absolute(fullPath));
	auto absPath = fs::absolute(relativePath);
	nf.build(fullPath.string());
	std::unique_ptr<Checksums::TreeElements::FileTreeElement> res = nf.getResult();
	Checksums::Visitors::HashStreamWriter rwv(file, std::move(md5));
	std::shared_ptr<Checksums::Observers::ObserverBase> pr = std::make_shared<Checksums::Observers::ProgressReporter>(res->getSize());
	rwv.addObserver(pr);
	res->accept(rwv);


	return 0;
}
