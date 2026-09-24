// newton.cpp
// Homework 4 - Exercise 5

#include <iostream> //cannot use println (produces error must use std::cin) 
#include <functional>

using std::function;

double newton_root( function<double(double)> f,
		    function<double(double)> fprime ) { // f and fprime passed as functions (one arguement) 
  double x = 1.0; //what I chose to use as the starting guess 
  for ( int it=0; it<100; it++ ) { //using x the update the newton method function 
    double fx = f(x); //solver
    if ( fx > -1e-9 && fx < 1e-9 ) //checking to see how close fx is to 0 
      return x;
    x = x - fx / fprime(x);
  }
  return x; //returns the best value we have produced so far 
}

int main() {

  double n;
  std::cin >> n; //takaes input for square root

  if ( n < 0 ) { //sqaure root cannot be negative 
    std::cout << "Error: number must be nonnegative.\n";
    return 1;
  }

  // f(x) = x*x - n (n is constant so we can use as capture and f only will depend on x then) 
  auto f = [n] (double x) { return x*x - n; };
  auto fprime = [] (double x) { return 2*x; }; //only uses x (because derivative) so n is not needed in this lambda function 

  double root = newton_root( f, fprime );
  std::cout << "sqrt(" << n << ") = " << root << std::endl;

  return 0;
}
