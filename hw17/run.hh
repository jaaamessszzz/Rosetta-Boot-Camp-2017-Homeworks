// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#include <cstdlib>
#include <iostream>
#include "Landscape.cc"
#include "Coordinates.hh"
#include "MonteCarlo.hh"
#include "Uniform.cc"

int run(
	std::string const & function_name,
	double input_x,
	double input_y,
	int outer,
	int inner,
	int output_every_n_steps = 1 // in between however many inner steps do we output
);
