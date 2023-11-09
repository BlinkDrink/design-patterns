#include "Utils.h"

void removeTrailingZeroes(string& s)
{
	s.erase(s.find_last_not_of('0') + 1, std::string::npos);
	if (s.back() == '.')
		s.pop_back();
}
