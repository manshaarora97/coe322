// main file 

#include <iostream>
#include "collatz.h" // learned that this will be beneficial (puts all contents of collatz.h into main)  

using std::cin;

int main()
{
  int start;

    // user input for value instead of hardcoded .
    cin >> start;

    // Compute the sequence length using the separately compiled function (calls function in collatz.cpp) 
    int length = sequence_length(start);

    // Print just the length.
    std::cout << length << std::endl; 

    return 0;

}
