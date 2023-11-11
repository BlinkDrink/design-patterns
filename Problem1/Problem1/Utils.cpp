#include "Utils.h"
#include <random>

void remove_trailing_zeroes(string& s)
{
	s.erase(s.find_last_not_of('0') + 1, std::string::npos);
	if (s.back() == '.')
		s.pop_back();
}

double generate_random_double_number(double lower_bound, double upper_bound)
{
	static std::uniform_real_distribution<double> urd(lower_bound, upper_bound);
	static std::default_random_engine re;
	return urd(re);
}