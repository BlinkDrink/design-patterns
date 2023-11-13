#pragma once
#include <random>

#include "RandomGenerator.h"

class DoubleGenerator : public RandomGenerator
{
public:
	/**
	 * \brief Generate a double number in the range 0 to max
	 * \param min - lower bound for the generated number
	 * \param max - upper bound for the generated number
	 * \return - randomly generated double
	 */
	double Generate(double min, double max) override;
};