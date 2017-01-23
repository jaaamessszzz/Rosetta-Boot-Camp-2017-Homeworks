#include <iostream>

int main() {
  
  std::cout << "Enter the pine tree's height as an integer: ";
  int height;
  std::cin >> height;

  int tree_height = 0;
  while (tree_height < height + 1)
    {
      // Print stars for the tree
      for(int count=0; count < height-tree_height; ++count)
        std::cout << " ";

      for(int count=0; count < (tree_height * 2 - 1); ++count)
        std::cout << "*";

      std::cout << std::endl;

      ++tree_height;

    }

  // Print the trunk
  for (int count=0; count < height-1; ++count)
    std::cout << " ";

  std::cout << "|" << std::endl;

  // Assignment:
  // Write code here to draw a pine tree.
  // If the height given is "3" then the pine tree should look like this:
  //   *
  //  ***
  // *****
  //   |
  //
  // If the height given is "5" then the pine tree should look like this:
  //     *
  //    ***
  //   *****
  //  *******
  // *********
  //     |
  //
  // where the height represents the number of rows of stars.  The trunk should
  // always be there.  Don't worry about writing code to verify that the input
  // is an integer (though, kudos if you did think about that being necessary!)
    
  return 0;
}
