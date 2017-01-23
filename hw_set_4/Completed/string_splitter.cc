// This homework assignment is less about the mechanics of C++
// (inheritance, pointers, references) and more about problem
// solving.  This one in particular is meant to ease you into
// one of the more demanding tasks you'll encounter at boot camp.
// In the past few boot camps, lab 4 (2nd evening lab) has
// been pretty tough for people.  So this homework is meant to
// prime you for one of the challenges that the lab presents.
//
// The assignment in this lab is to write a function that takes
// a string of "1"s and "0"s and describes it as a set of 1s
// blocks and 0s blocks.  For the input string
// 000001111110000111111110000
// your function should return a std::vector of ints where each
// entry in this vector represents a transition point from
// one character into the other
// in this case,
// 012345678901234567890123456 <-- ruler
// 000001111110000111111110000
// the correct output would be a vector containing
// 5,11,15,23
// where these are ("0" indexed) positions where the character
// changes from its initial value to a different value.
// Your function should have the following signature:
//
// std::vector< int >
// split_zero_and_ones_string( std::string const & input_string );
//
// The way your assignment will be graded is by replacing your int main()
// with a new one which will call split_zero_and_ones_string().
//
// Think hard about how you test your function.  What are the "edge cases"
// where your function might fail? You can be pretty sure that I'll find
// those edge cases, so look closely for them.  (You may assume that the
// input string contains only 0s and 1s).

#include <iostream>
#include <vector>
#include <string>

std::vector<int> return_vector(std::string const & user_input){

    std::vector<int> split_indicies;
    char current_char = user_input[0];

    for(int counter = 0; counter < user_input.length(); counter++){
//        Ruler
//        std::cout << user_input[counter] << " | " << counter << std::endl;

        if (user_input[counter] != current_char){
            split_indicies.push_back(counter);
            current_char = user_input[counter];
        }
        else;
    }

    return split_indicies;
}

int main(){
    std::string user_input;
    std::vector<int> final_vector;
    std::cout << "Input your string of 1's and 0's:" << std::endl;
    std::cin >> user_input;

    final_vector = return_vector(user_input);

    for (std::vector<int>::iterator ii = final_vector.begin(); ii != final_vector.end(); ++ii)
        std::cout << ' ' << *ii;
    std::cout << std::endl;

    return 0;
}