// newton.cpp
// Homework 7- Homework 5

#include <iostream> //cannot use println (produces error must use std::cin) 
#include <functional>

using std::function;

double newton_root( function<double(double)> f,
		    function<double(double)> fprime ) { //creating a two arguement version of homework 4 
  double x = 1.0; //what I chose to use as the starting guess 
  for ( int it=0; it<100; it++ ) { //using x the update the newton method function 
    double fx = f(x); //solver
    if ( fx > -1e-9 && fx < 1e-9 ) //checking to see how close fx is to 0 
      return x;
    x = x - fx / fprime(x);
  }
  return x; //returns the best value we have produced so far 
}
// Excerise 7 version of last hw but only takes in f

double newton_root( function<double(double)> f ) {
  const double h = 1e-6; // fixed finit value 
 
  
  auto fprime = [f, h] (double x) {
    return ( f(x + h) - f(x - h) ) / ( 2.0 * h ); // central difference approximation of f'(x)
  };
 
  return newton_root(f, fprime); // reuse the hw4 Newton solver, no loop rewritten here
}
//one argument exercise 7:
double newton_root(function<double(double> f) {
    const double h = 1e-6; //fixed step
   
int main() {

  double n;
  std::cin >> n; //takaes input for square root

  if ( n < 0 ) { //sqaure root cannot be negative 
    std::cout << "Error: number must be nonnegative.\n";
    return 1;
  }

  // f(x) = x*x - n (n is constant so we can use as capture and f only will depend on x then) 
  auto f = [n] (double x) { return x*x - n; }; 

  double root = newton_root( f);
  std::cout << "sqrt(" << n << ") = " << root << std::endl;

  return 0;
}
