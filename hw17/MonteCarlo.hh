// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#ifndef INCLUDED_MonteCarlo_hh
#define INCLUDED_MonteCarlo_hh

#include "Coordinates.hh"
#include "Uniform.cc"

///// This part is the declarations of the MonteCarlo Class /////
///// The only code you have to write in this file are delcarations of member variables

class MonteCarlo {
public:

	// Constructor
	// Usage: MonteCarlo mc = MonteCarlo(xyz, temp)
	MonteCarlo( Coordinates & xyz, float temperature );

	~MonteCarlo();

	// Get/Set the stored temperature factor used in the boltzmann calculation
	void set_temperature( float temp );
	float get_temperature() const;

	// This is the workhorse for MonteCarlo Class
	// This function compares the z values of the new Coordinates "new_xyz" and the stored Coordinates "last_accepted_xyz_".

	// Behavior:
	// If the "new_xyz" has a lower z (score), the function will always accept the new_xyz
	// If the "new_xyz" has a higher z (score), the function will still sometimes accept the "new_xyz" with a certain probability, based on the value of the "temperature_" variable. The higher the temperature, the easier to accept higher z values.

	// If the "new_xyz" coordinate is accepted, the stored "last_accepted_xyz_" will be set to this new value, and return true.
	// If the new coordinate "new_xyz" is rejected, the passed-in "new_xyz" coordinate will be overwritten with the stored "last_accepted_xyz_" value, and false will be returned.
	bool boltzmann(Coordinates & new_xyz);

	// The last Coordinates value that was accepted
	Coordinates const & get_last_accepted_coordinates() const { return last_accepted_xyz_;}

	// The last z (score) value that was accepted
	double last_accepted_z() const;

private:
	Uniform uniformRG_; // You shouldn't need to do anything in MonteCarlo.cc to initialize this - just use it!
	// TODO for you: declare the additional class member variables you use here
	Coordinates last_accepted_xyz_;
	Coordinates new_xyz;
	float temp_;
};

#endif
