#include <filesystem>
#include <iostream>
#include <memory>

#include "FollowLinksBuilder.h"
#include "NoFollowLinksBuilder.h"
#include "ReportWriter.h"
#include "HashStreamWriter.h"
#include "MD5ChecksumCalculation.h"
#include "PauseScanner.h"
#include "ProgressReporter.h"
#include "SHA256ChecksumCalculation.h"

namespace fs = std::filesystem;

int main()
{
	Checksums::Scanners::PauseScanner ps;
	while (true)
	{
		std::string cmd, path, finalPath;
		std::cout << "Enter path to file/directory:";
		std::cin >> path;
		const fs::path currentPath = fs::current_path();
		const fs::path pathToPrint = currentPath / path;

		if (fs::exists(path))
		{
			finalPath = path;
		}
		else if (fs::exists(pathToPrint))
		{
			finalPath = path;
		}
		else
		{
			std::cout << "Invalid path to file";
		}

		std::unique_ptr<Checksums::Builders::BuilderBase> builder;
		std::string links;
		std::cout << "Do you wish to follow symbolic links/shortcuts?";
		std::cin >> links;
		if (links == "yes")
		{
			builder = std::make_unique<Checksums::Builders::FollowLinksBuilder>();
		}
		else
		{
			builder = std::make_unique<Checksums::Builders::NoFollowLinksBuilder>();
		}

		builder->build(finalPath);
		auto tree = builder->getResult();

		std::cout << "\nEnter command:";
		std::cin >> cmd;

		if (cmd == "report")
		{
			Checksums::Visitors::ReportWriter rw(std::cout);
			tree->accept(rw);
		}
		else if (cmd == "calculate")
		{
			std::string checksumPath, alg;
			std::unique_ptr<Checksums::ChecksumCalculations::ChecksumCalculationBase> hashAlg;
			std::cout << "Enter path to file in which checksums will be written in format <hash> <filePath>:";
			std::cin >> checksumPath;
			std::ofstream output(checksumPath);
			if (!output.is_open())
				throw std::invalid_argument("Couldnt open " + checksumPath + " for writing");
			std::cout << "Enter algorithm for checksums (md5/sha256):";
			std::cin >> alg;
			if (alg == "md5")
				hashAlg = std::make_unique<Checksums::ChecksumCalculations::MD5ChecksumCalculation>();
			else if (alg == "sha256")
				hashAlg = std::make_unique<Checksums::ChecksumCalculations::SHA256ChecksumCalculation>();

			Checksums::Visitors::HashStreamWriter hsw(output, std::move(hashAlg));
			tree->accept(hsw);
		}
		else if (cmd == "pause")
		{

		}
		else if (cmd == "resume")
		{

		}
		else if (cmd == "exit")
		{
			return 0;
		}
	}
}
