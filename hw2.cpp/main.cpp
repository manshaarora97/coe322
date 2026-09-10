#include <iostream>

using std::cout;

int main() {
  int max_length = 0;

  for(int i = 1; i <= 1000; i++) { // loop iterates through all possible values 

    int length = sequence_length(i);

if (length > max_length) { //if the sequence right now is longer than previous \
update max length record                                                        
      max_length = length;
      cout << i << "\n";
    }

  }

  return 0;

}


























-UUU:**--F1  hw2.cpp        Bot L49    (C++//l Abbrev) -------------------------
