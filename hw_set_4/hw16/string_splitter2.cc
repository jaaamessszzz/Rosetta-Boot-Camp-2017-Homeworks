// This assignment builds on the string splitter function you wrote in
// the previous one.  In this assignment, instead of your input consisting
// of only 1s and 0s, it may now consist of any number of different
// numbers (between 0 and 9).  In this case, you care about the 1s
// and the 0s, but there might be 2s and 3s etc. mixed in.
//
// Your function should report the beginning and ending possition for
// each block of 0s and 1s.  Use the struct below to report a pair of
// positions:
#include <iostream>
#include <vector>
#include <string>

struct start_and_stop {
  int start_;
  int stop_;
};

// So for example, the input string (ignore the two ruler lines)
//
// 00000000001111111111222222222233333333334 <-- ruler tens
// 01234567890123456789012345678901234567890 <-- ruler ones
//
// 00001110293411111887888880000222333311111 <-- the input string
// should report the following starting and stopping
// positions:
// start stop
//     0    3
//     4    6
//     7    7
//    12   16
//    25   28
//    36   40
// Notice that the blocks of non-0s and non-1s are basically ignored.
//
// Your function should have the following signature.
// std::vector< start_and_stop >
// split_zeros_and_ones_blocks_from_string( std::string const & input_string );
//
// Grading will work as it did for the previous assignment -- your int main() will
// be replaced with another one that will call your function and make sure it 
// produces the correct answers.  Think hard about edge cases.

std::vector< start_and_stop > split_zeros_and_ones_blocks_from_string( std::string const & input_string ){
    std::vector<start_and_stop> final_vector;

    std::string asdf = "01";
    char zero = asdf[0];
    char one = asdf[1];

    char current_block_type;
    int start = -1;
    int stop = -1;

    start_and_stop current_block;

    bool record = false;

    // For every number in the string that gets passed in...
    for (int counter = 0; counter < input_string.length(); counter++){

        // If the character is a "0" or "1"...
        if (input_string[counter] == one || input_string[counter] == zero ){

            // Are we record the indicies for the block?
            if (record == false){
                // If record == false, then remember the starting index for the current block of 1's or 0's
                // Also remember the block type we are recording indicies for (1's or 0's)
                // Set record == true, so we will record the ending index as long as
                // (input_string[counter] == one || input_string[counter] == zero ) remains true

                record = true;
                current_block_type = input_string[counter];
                start = counter;
            }

            else {
                // If record == true, then we are either:
                //   A. Recording in the same block type, continue recording the ending index until
                //      (input_string[counter] == one || input_string[counter] == zero ) becomes false
                //   B. Went from a block of 0 to 1, or vice versa. Record the previously recorded starting and ending
                //      indicies, commit them to final_vector, then start a new block where start = counter.

                // Option B
                if(input_string[counter] != current_block_type){

                    // Record previous starting and ending indicies
                    current_block.start_ = start;
                    current_block.stop_ = counter - 1;

                    // Push indicies to final_vector
                    final_vector.push_back(current_block);

                    // Switch from 0 -> 1 or 1 -> 0
                    current_block_type = input_string[counter];

                    // Start a new block
                    start = counter;
                }

                // Option A
                else stop = counter;
            }

        }

        // We enter this block when:
        //   A. We exit a block of 1's or 0's
        //   B. We are continuing in a block of not 1's and 0's

        else {
            // Option A
            // If we were previously recording, set record to false and commit starting/ending indices to final_vector
            if (record == true){
                record = false;
                current_block.start_ = start;
                current_block.stop_ = counter - 1;

                final_vector.push_back(current_block);
            }

            // Option B
            // Do nothing.
            else;
        }

        std::cout << input_string[counter] << " | " << counter << "\t| " << record << std::endl;

        //Checking last integer in string
        if (counter == (input_string.length() - 1) && record == true){
            current_block.start_ = start;
            current_block.stop_ = counter;

            final_vector.push_back(current_block);
        }
        else;
    }



    return final_vector;
}

int main(){
    std::string user_input;
    std::vector<start_and_stop> final_vector;

    std::cout << "Input your string of numbers:" << std::endl;
    std::cin >> user_input;

    final_vector = split_zeros_and_ones_blocks_from_string(user_input);

    for (std::vector<start_and_stop>::iterator ii = final_vector.begin(); ii != final_vector.end(); ++ii)
        std::cout << ii->start_ << " " << ii->stop_ << std::endl;
    std::cout << std::endl;

    return 0;
}