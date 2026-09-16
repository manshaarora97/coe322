// collatz.cpp
//
// Implements sequence_length, declared in collatz.h.

#include "collatz.h"

int sequence_length(int start) //takes in a single int value 
{
    int n = start; 
    int steps = 0;

    while (n != 1) //makes sure it continues looping until it becomes 1
    {
      if (n % 2 == 0) //if n is even then divide by 2 
        {
            n = n / 2;
        }
        else
        {
	  n = 3 * n + 1; //if n is odd then multiply and add 
        }
      steps++; //counter for how many iterations it takes 
    }

    return steps; //return int value of iterations (amount of steps it took to get to 1 from start) 
}
