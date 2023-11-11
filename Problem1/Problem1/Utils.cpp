#include "Utils.h"
#include <random>

void removeTrailingZeroes(string& s)
{
	s.erase(s.find_last_not_of('0') + 1, std::string::npos);
	if (s.back() == '.')
		s.pop_back();
}

double generateRandomDoubleNumber(double lower_bound, double upper_bound)
{
	std::uniform_real_distribution<double> urd(lower_bound, upper_bound);
	std::default_random_engine re;
	return urd(re);
}