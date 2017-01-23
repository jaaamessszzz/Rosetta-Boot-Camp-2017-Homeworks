#include <iostream>
#include <string>
#include <math.h>

// Assignment:
//
// Write a "Patient" class here that represents patient data for a medical clinic.
//
// Patient data to store:
// * Name (a single C++ std::string)
// * Current height (in m)
// * Current weight (in kg)
//
// The data should be encapsulated (private).
// No direct access to the data should be allowed,
// only access data through class member functions (see below).
//
// You should provide a way to construct a patient class with a name,
// as well name is as one where no availible yet.
// (Use a value of "0" to represent an unknown height or weight,
// and an empty string to represent an unknown name.)
//
// Three methods ("set_name", "set_height", "set_weight") should be provided
// which allow you to individually change the name, the height, or the weight.
// - You should check that the provided height and weight are positive,
//   and set them to the unknown values (see above) if they are invalid (negative).
//
// Three additional methods ("get_name", "get_height", "get_weight")
// should allow you to obtain the name, height and weight of a patient.
//
// You should also provide a method ("bmi") which calculates
// the patient's BMI (body mass index) and returns it.
// (The BMI is the weight in kg divided by the square of the height in meters:
//   http://en.wikipedia.org/wiki/Body_mass_index).
// If either the height or weight is unknown, return "0" for the BMI.
//
// For the moment ignore any complications regarding the validity
// of BMI for assessing health, or complications regarding applying
// it to any particular group of people (like infants).

class Patient{

private:
    std::string name;
    double current_height = 0;
    double current_weight = 0;

public:
    Patient(std::string nameeeee);
    Patient();

    void set_name(std::string);
    void set_height(double);
    void set_weight(double);

    std::string get_name();
    double get_weight();
    double get_height();

    double bmi();

};

Patient::Patient(std::string nameee) {
    if (nameee != "") name = nameee;
    else;
}

Patient::Patient(){}

void Patient::set_name(std::string setting_name){name = setting_name;}
std::string Patient::get_name(){
    if (name == "") return "";
    else return name;
}

void Patient::set_height(double setting_height){
    if (setting_height > 0) current_height = setting_height;
    else current_height = 0;
}

    double Patient::get_height(){
    return current_height;
}

void Patient::set_weight(double setting_weight){
    if (setting_weight > 0) current_weight = setting_weight;
    else current_weight = 0;
}

double Patient::get_weight(){
    return current_weight;
}

double Patient::bmi(){
    if (current_height == 0 || current_weight == 0)
        return 0;
    else
        return current_weight/ pow(current_height, 2);
}

int main() {

  Patient father("Andrew Nonymous");
  Patient mother("Ursula N. Known");
  Patient baby;

  //Father's height and weight are unknown.

  mother.set_name("Ursula N. Nonymous");
  mother.set_height(1.65);
  mother.set_weight(58);

  baby.set_height(0.495);
  baby.set_weight(3.4);

  std::cout << "Baby: " << baby.get_name() << " BMI: " << baby.bmi() << std::endl;
  std::cout << "Mother: " << mother.get_name() << " BMI: " << mother.bmi() << std::endl;
  std::cout << "Father: " << father.get_name() << " BMI: " << father.bmi() << std::endl;

  return 0;
}
