// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

/// This Coordinates class contains three double numbers, x_, y_, z_,
/// which are used to describe the coordinates of a point in 3-D dimension.
/// Users can set and modify x_ and y_, and calculate z_, according certain Function.
/// In this exercise, we are only dealing with three functions

#ifndef INCLUDED_Coordinates_hh
#define INCLUDED_Coordinates_hh

#include <iostream>
#include <stdexcept>
#include <memory>
#include "Landscape.cc"

///// This part is the declarations of the Coordinates Class /////
///// The only code you have to write in this file are the delcarations of member variables

class Coordinates {

public:
	// Default constructor for Coordinates class
	Coordinates();

	// Constructor with input Landscape function name,
	// currently, there are only three choices: "sum_squares", "ackley", and "rastrigin"
	Coordinates(std::string fxn);

	// Copy constructor
	// This constructor must copy all member variables from the "src" object, to the
	// Coordinates object being created by this constructor. Make sure that no data members
	// are skipped. For the "landscape_" data member, a shallow copy of the pointer itself
	// is ok.
	Coordinates(Coordinates & src);

	// Destructor. The destructor must be implemented in the .cc file, even though it will be
	// empty -- litterally, the function body will be "{}"
	~Coordinates();

	// X Getters and setters
	double get_x();
	void set_x(double x);
	// Modify the stored X value by adding "delta" to it, and saving
	void modify_x(double delta);

	// Y Getters and setters
	double get_y();
	void set_y(double y);
	// Modify the stored Y value by adding "delta" to it, and saving
	void modify_y(double delta);

	// Get the z value
	// Note: we are not providing a setter function for z, because the z value is calculated from (x,y)
	// by using the update_z() function;
	// The z value represents to the score of the (x,y) coordinates
	// This getter retrieves the cached z value saved in the member variable z_ : you should make sure
	// this cached member variable is always updated if x or y are changed.
	double get_z() const ;
	double calculate_z(double x, double y);

	// Get/set a string representing the landscape function. We lookup the appropriate function
	// to calculate the z value/score from this string name.
	// We have already implemented this function for you in Coordinates.cc
	void set_landscape_function(std::string new_function);

	std::string get_landscape_function();

	void reset_temp_xy();

	double get_temp_x();
	double get_temp_y();

protected:
	// Update the stored z value (score) using the landscape energy function
	void update_z();

private:
	std::shared_ptr<Landscape> landscape_;
	// TODO for you: declare the additional class member variables you use here
	// you will want to store the coordinates and the value returned by the landscape_
	std::string landscape_function_name_;
	double x_;
	double y_;
	double z_;
	double temp_x_;
	double temp_y_;
};

#endif
