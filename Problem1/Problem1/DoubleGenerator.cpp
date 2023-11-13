#include "DoubleGenerator.h"
#include <random>

double DoubleGenerator::Generate(double min, double max)
{
	std::uniform_real_distribution<double> urd(min, max);
	static std::default_random_engine re(time(nullptr)); // Initialize the random engine only once during execution time to keep the results random
	return urd(re);
}
