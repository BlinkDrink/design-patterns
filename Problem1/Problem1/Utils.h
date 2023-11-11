#pragma once
#include<iostream>
using std::string;

/**
 * \brief Remove the trailing zeroes from s and possibly the comma (if the string representation of number has no decimal part)
 * \param s - the string representation of a number to be formatted
 */
void removeTrailingZeroes(string& s);

/**
 * \brief Generates a random double in the given range
 * \return 
 */
double generateRandomDoubleNumber(double lower_bound, double upper_bound);