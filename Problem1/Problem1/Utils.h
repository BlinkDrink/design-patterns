#pragma once
#include<iostream>
using std::string;

namespace Problem1
{
	namespace Utils
	{
		/**
		 * \brief Remove the trailing zeroes from s and possibly the comma (if the string representation of number has no decimal part)
		 * \param s - the string representation of a number to be formatted
		 */
		void remove_trailing_zeroes(string& s);
	}
}