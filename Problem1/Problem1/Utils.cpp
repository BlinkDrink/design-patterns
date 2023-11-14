#include "Utils.h"
#include <random>

namespace Problem1
{
	namespace Utils
	{
		void remove_trailing_zeroes(string& s)
		{
			s.erase(s.find_last_not_of('0') + 1, std::string::npos);
			if (s.back() == '.')
				s.pop_back();
		}
	}
}
