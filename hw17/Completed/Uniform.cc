// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#ifndef INCLUDED_Uniform_cc
#define INCLUDED_Uniform_cc

// This class generates uniform random numbers, using a seed
// For the Rosetta equivalent, see the source code in Rosetta/main/source/src/numeric/random/

// NOTE:
// Don't change the seed functionality to be able to compare to the expected program output

// Bonus: Can you write a new random generator, which can generate gaussian random number
// (normally distributed deviate with zero mean and unit variance) ?

#include <cstdlib>

class Uniform {
public:
	Uniform():
		seed_(0) // Clear, for consistent starting state
	{}

	~Uniform() {}

	void setSeed(int const seed) { seed_ = seed; srand( seed_ ); }
	int getSeed() { return seed_; }


	double getRandom() { return (double)rand() / (double)RAND_MAX; }

private:
	int seed_;
};

#endif
