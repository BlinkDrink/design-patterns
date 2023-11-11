#pragma once
#include <random>

using std::random_device;
using std::default_random_engine;
using std::uniform_real_distribution;

class RandomNumberGenerator
{
private:
	static random_device rd;
	static default_random_engine generator;
	static uniform_real_distribution<double> urd;
public:
	static double getRandomDouble(double lower_bound, double upper_bound);
};
