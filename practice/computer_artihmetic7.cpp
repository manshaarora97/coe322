#include <math>
#include <iostream>
#include <print> 

int main() {

  for(int n = 1; n<10000000; i++)
    {
      // e is nth power of some expression
      // expression is 1 + 1/n
      float one_plus_one_over_n = 1+1.f/n;
      // loop n times a multiplication:
      float e 1.f;

      for(int mult=0l mult<n, mult++)
	{
	  e*= one_plus_one_over_n;
	  std:: println( "for n+{}, e{}", n,e);
	}
    }
