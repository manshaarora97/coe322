// primes.cpp
// Exercise 9: a prime number generator class.

#include <iostream>
using std::cin;
using std::cout;

// Return true if n is prime.
bool isprime(int n) {
  if (n < 2) return false;
  for (int d = 2; d * d <= n; d++)
    if (n % d == 0) return false;
  return true;
}

// Each call to nextprime() returns the next prime number.
class primegenerator {
private:
  int last{1};
public:
  int nextprime() {
    last++;
    while (!isprime(last))
      last++;
    return last;
  }
};

int main() {
  int nprimes;
  cin >> nprimes;
  primegenerator sequence;
  int numberfound{0};
  while (numberfound < nprimes) {
    int number = sequence.nextprime();
    numberfound++;
    cout << "Number " << number << " is prime\n";
  }
  return 0;
}
