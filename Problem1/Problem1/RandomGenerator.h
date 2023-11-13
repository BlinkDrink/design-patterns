#pragma once

/**
 * \brief Abstract base class for everything that will generate a random value in the interval 0 to max
 */
class RandomGenerator
{
public:
	virtual double Generate(double min, double max) = 0;
    virtual ~RandomGenerator() = default;
};