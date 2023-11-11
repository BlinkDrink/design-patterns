#include "Utils.h"
#include <random>
#include "RandomNumberGenerator.h"

using std::default_random_engine;

void remove_trailing_zeroes(string& s)
{
	s.erase(s.find_last_not_of('0') + 1, std::string::npos);
	if (s.back() == '.')
		s.pop_back();
}

// TODO: default_random_engine is seeded with the same starting point on each generation, thus generating the same numbers
double generate_random_double_number(double lower_bound, double upper_bound)
{
	return RandomNumberGenerator::getRandomDouble(lower_bound, upper_bound);
}