// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#include <cstdlib>
#include <cmath>
#include "Coordinates.hh"
#include "MonteCarlo.hh"
#include "Uniform.cc"

///// The following part contains the implementations of the MonteCarlo Class /////
///// Fill in below implementations of the constructors and other functions defined in MonteCarlo.hh

MonteCarlo::MonteCarlo(Coordinates & xyz, float temperature){
    new_xyz = xyz;
    last_accepted_xyz_ = xyz;
    temp_ = temperature;
}

MonteCarlo::~MonteCarlo() {}

void
MonteCarlo::set_temperature( float temp ){
    temp_ = temp;
}

float
MonteCarlo::get_temperature() const {
    return temp_;
}

bool
MonteCarlo::boltzmann(Coordinates & new_xyz){

    if(new_xyz.get_z() < last_accepted_z()){
        last_accepted_xyz_ = new_xyz;
        return true;
    }

    else{
        double probabililty =  std::exp( -( new_xyz.get_z() - last_accepted_z() ) / (temp_) );

        if (probabililty > uniformRG_.getRandom()){
            last_accepted_xyz_ = new_xyz;
            return true;
        }
        else {
            new_xyz.reset_temp_xy();
            return false;
        }
    }
}

double
MonteCarlo::last_accepted_z() const {
    return last_accepted_xyz_.get_z();
}