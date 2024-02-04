#include "Engine.h"

#include<string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include "NoFollowLinksBuilder.h"
#include "ChecksumCalculationFactory.h"
#include "MD5ChecksumCalculation.h"
#include "ScannerMessage.h"

class Scanner : Checksums::Observers::ObservableBase {
	std::mutex mutex_;
	std::condition_variable cv_;
	std::atomic<bool> paused_{ false }, stopped_{ false };
	std::thread scanThread_;
	std::unique_ptr<Checksums::TreeElements::FileTreeElement> rootDirectory_;
	std::shared_ptr<Checksums::Visitors::VisitorBase> visitor_;

	void scan()
	{
		std::unique_lock<std::mutex> lock(mutex_, std::defer_lock);
		lock.lock();
		cv_.wait(lock, [this] { return !paused_ || stopped_; });
		lock.unlock();

		rootDirectory_->accept(*visitor_);
	}

public:
	Scanner(std::unique_ptr<Checksums::TreeElements::FileTreeElement> root, std::shared_ptr<Checksums::Visitors::VisitorBase> visitor) : rootDirectory_(std::move(root)), visitor_(visitor) {}

	void start() {
		stopped_ = false;
		paused_ = false;
		scanThread_ = std::thread(&Scanner::scan, this);
	}

	void pause() {
		paused_ = true;
		std::shared_ptr<Checksums::Messages::Message> pauseMsg = std::make_shared<Checksums::Messages::ScannerMessage>("pause");
		notifyObservers(pauseMsg);
	}

	void resume() {
		paused_ = false;
		std::shared_ptr<Checksums::Messages::Message> resumeMsg = std::make_shared<Checksums::Messages::ScannerMessage>("resume");
		notifyObservers(resumeMsg);
		cv_.notify_one();
	}

	void stop() {
		stopped_ = true;
		resume();
		if (scanThread_.joinable()) scanThread_.join();
	}

	void addObserver(std::shared_ptr<Checksums::Observers::ObserverBase> observer)
	{
		Checksums::Observers::ObservableBase::addObserver(observer);
	}

	~Scanner() {
		stop();
	}
};

std::shared_ptr<Checksums::Visitors::VisitorBase> initializeHashStreamWriter() {
	std::string checksumPath, alg;
	std::unique_ptr<Checksums::ChecksumCalculations::ChecksumCalculationBase> hashAlg;
	while (true)
	{
		std::cout << "Enter path to file in which checksums will be written in format <hash> <filePath>:";
		std::cin >> checksumPath;
		std::ofstream output(checksumPath);
		if (!output.is_open())
		{
			std::cout << "Couldn't open file for reading";
		}
		else
		{
			std::cout << "Enter algorithm for checksums (md5/sha256):";
			Checksums::Factories::ChecksumCalculationFactory calcFactory(std::cin);
			return std::make_shared<Checksums::Visitors::HashStreamWriter>(std::move(output), calcFactory.create_calculator());
		}
	}
}

int main()
{
	//Checksums::Engines::Engine::getInstance().exe();
	std::string rootPath = "D:\\Learning\\DesignPatterns\\design-patterns\\Problem3\\Checksums\\Checksums\\mock_directory1";
	std::string outputPath = "/path/to/output.txt";
	std::ofstream outputFile(outputPath);

	// Setup directory builder and checksum calculator
	Checksums::Builders::NoFollowLinksBuilder builder;
	builder.build(rootPath);
	auto rootDirectory = builder.getResult();
	auto checksumCalculator = std::make_unique<Checksums::ChecksumCalculations::MD5ChecksumCalculation>();

	// Setup visitors
	std::shared_ptr<Checksums::Observers::ObservableBase> hashStreamWriter = std::make_shared<Checksums::Visitors::HashStreamWriter>(outputFile, std::move(checksumCalculator));
	std::shared_ptr<Checksums::Observers::ObserverBase> progressReporter = std::make_shared<Checksums::Observers::ProgressReporter>(rootDirectory->getSize());
	hashStreamWriter->addObserver(progressReporter);

	Checksums::Visitors::VisitorBase* v = dynamic_cast<Checksums::Visitors::HashStreamWriter*>(hashStreamWriter.get());
	Checksums::Observers::ObserverBase* v1 = dynamic_cast<Checksums::Visitors::HashStreamWriter*>(hashStreamWriter.get());
	std::shared_ptr<Checksums::Visitors::VisitorBase> hsw = std::shared_ptr<Checksums::Visitors::VisitorBase>(v);
	std::shared_ptr<Checksums::Observers::ObserverBase> hsw2 = std::shared_ptr<Checksums::Observers::ObserverBase>(v1);

	// Start scanning process
	Scanner scanner(std::move(rootDirectory), hsw);
	scanner.addObserver(hsw2);
	scanner.addObserver(progressReporter);
	scanner.start();


	// User command loop
	std::string command;
	while (true) {
		std::cout << "Enter command (pause, resume, stop): ";
		std::cin >> command;
		if (command == "pause") {
			scanner.pause();
		}
		else if (command == "resume") {
			scanner.resume();
		}
		else if (command == "stop") {
			scanner.stop();
			break;
		}
	}

	return 0;
}
