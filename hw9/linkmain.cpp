// linkmain.cpp -- Exercise 10.
// Read positive integers from standard input, build a sorted linked list
// that counts repeated values, stop at 0 (or end of input), print the list.
// Example: input 5 7 5 8 0  gives  5:2 7:1 8:1
#include <iostream>
#include <print>
#include "linklib.hpp"

int main() {
  List mylist;
  int number;
  // `cin >> number` fails on end-of-input or non-numeric text; then we stop.
  while (std::cin >> number) {
    if (number == 0)
      break;                       // sentinel: stop reading
    if (number < 0) {              // only positive integers are accepted
      std::println(stderr, "Ignoring non-positive input: {}", number);
      continue;
    }
    mylist.insert(number);
  }
  mylist.print();
  return 0;
}
