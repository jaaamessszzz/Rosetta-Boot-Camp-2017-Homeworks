// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

/// This Coordinates class contains three double numbers, x_, y_, z_,
/// which are used to describe the coordinates of a point in 3-D dimension.
/// Users can set and modify x_ and y_, and calculate z_, according certain Function.
/// In this exercise, we are only dealing with three functions

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "Landscape.cc"
#include "Coordinates.hh"

///// Implementation of Coordinates functions starts here /////
///// TODO: Implementat the constructors and member functions for class Coordinates
///// that are declared in Coordinates.hh

// We have already implemented this function for you. You should invoke
// this function in the constructor.
void
Coordinates::set_landscape_function(std::string new_function) {

	landscape_function_name_ = new_function;

	if ( landscape_function_name_ == "sum_squares" ) {
		landscape_ = std::shared_ptr<Landscape> ( new SumSquares() );
	} else if ( landscape_function_name_ == "rastrigin" ) {
		landscape_ = std::shared_ptr<Landscape> ( new Rastrigin() );
	} else if ( landscape_function_name_ == "ackley" ) {
		landscape_ = std::shared_ptr<Landscape> ( new Ackley() );
	} else {
		throw std::invalid_argument( "The function '" + new_function + "' hasn't been defined! Valid options are 'sum_squares', 'rastrigin', and 'ackley'" );
	}
}

Coordinates::Coordinates(){}
Coordinates::~Coordinates(){}

Coordinates::Coordinates(std::string fxn){
	set_landscape_function(fxn);
	x_ = 0;
	y_ = 0;
	z_ = 0;
	temp_x_ = 0;
	temp_y_ = 0;
}
Coordinates::Coordinates(Coordinates & src){
	x_ = src.get_x();
	y_ = src.get_y();
	z_ = src.get_z();
	temp_x_ = src.temp_x_;
	temp_y_ = src.temp_y_;
	landscape_ = src.landscape_;
	landscape_function_name_ = src.landscape_function_name_;
}


// X Getters and setters
double
Coordinates::get_x(){
	return x_;
}
void
Coordinates::set_x(double x){
	x_ = x;
	update_z();
}

void
Coordinates::modify_x(double delta){
	temp_x_ = x_;
	x_ = x_ + delta;
	update_z();
}

// Y Getters and setters
double
Coordinates::get_y(){
	return y_;
}
void
Coordinates::set_y(double y){
	y_ = y;
	update_z();
}

void
Coordinates::modify_y(double delta){
	temp_y_ = y_;
	y_ = y_ + delta;
	update_z();
}

// Z Getter and setter
double
Coordinates::get_z() const {
	return z_;
}

std::string
Coordinates::get_landscape_function(){
	return landscape_function_name_;
}

void
Coordinates::update_z() {
	z_ = landscape_->calculate_z(x_, y_);
}

void
Coordinates::reset_temp_xy(){
	x_ = temp_x_;
	y_ = temp_y_;
	update_z();
}

double
Coordinates::calculate_z(double x, double y){
	return (landscape_->calculate_z(x, y));
}

double
Coordinates::get_temp_x(){
	return temp_x_;
}
double
Coordinates::get_temp_y(){
	return temp_y_;
}