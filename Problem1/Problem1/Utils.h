#pragma once
#include<iostream>
using std::string;

/**
 * \brief Remove the trailing zeroes from s and possibly the comma (if the string representation of number has no decimal part)
 * \param s - the string representation of a number to be formatted
 */
void remove_trailing_zeroes(string& s);

/**
 * \brief Generates a random double in the given range
 * \return 
 */
double generate_random_double_number(double lower_bound, double upper_bound);