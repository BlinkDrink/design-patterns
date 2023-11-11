#include "RandomNumberGenerator.h"

random_device RandomNumberGenerator::rd;
default_random_engine RandomNumberGenerator::generator(rd());
uniform_real_distribution<double> RandomNumberGenerator::urd;

double RandomNumberGenerator::getRandomDouble(double lower_bound, double upper_bound)
{
	return urd(generator);
}

