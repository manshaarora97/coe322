                                                                
// Homework 8: Pascal's Triangle
// starting off with exercise 6 and working my way up

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// k spaces
void print_spaces(int k) {
  for (int i = 0; i < k; i++)
    {
      cout << " ";
    }
}

// how many digits a number will have
int count_digits(long long x) {
  int digits = 1;
  while (x >= 10)
    {
      x = x / 10;
      digits++;
    }
  return digits;
}


class TriangleStorage {
private:

  vector<long long> data; // all the numbers in the data set
  int rows; // number of rows

  int position(int r, int c) {
    if (r < 1 || c < 1 || c > r)
      throw string("that spot is not in the triangle"); // exception

    return r * (r - 1) / 2 + (c - 1);
  }

  // how many numbers do n rows need? 1 + 2 + ... + n
  int size_needed(int n)
  {
    return n * (n + 1) / 2;
  }

public:

  // starts "empty": really just row 1
  TriangleStorage() : data(1), rows(1) {}

  // a triangle with n rows, all zeros
  TriangleStorage(int n) : data(size_needed(n)), rows(n) {}

  int nrows() {
    return rows;
  }

  // Exercise 8
  void set(int r, int c, long long value) {
    data.at(position(r, c)) = value;
  }

  long long get(int r, int c) {
    return data.at(position(r, c));
  }

  // Exercise 9
  long long &operator[](int r, int c) {
    int p = position(r, c);

    if (r > rows) {
      rows = r;
      data.resize(size_needed(rows));
      // adds new space at the end without moving the old numbers
    }

    return data[p];
  }
};   // <- ends TriangleStorage


// Exercise 6
class Pascal {
private:

  TriangleStorage tri;
  int n;

public:
  Pascal(int n) : n(n) {
    for (int r = 1; r <= n; r++) {
      for (int c = 1; c <= r; c++) {
        if (c == 1 || c == r) {
          tri[r, c] = 1; // ends of the rows are always 1
        } else {
          // add the two numbers above to create all the other numbers
          tri[r, c] = tri[r - 1, c - 1] + tri[r - 1, c];
        }
      }
    }
  }

  // get number in each row and column
  long long getvalue(int i, int j) {
    return tri.get(i, j);
  }

  long long operator[](int i, int j) {
    return tri.get(i, j);
  }

  // code to print the whole triangle
  void print() {
    int width = count_digits(tri.get(n, (n + 1) / 2)) + 1;
    if (width % 2 == 1)
      width++; // makes sure triangle is centered

    for (int r = 1; r <= n; r++) {

      cout << "Row ";
      if (r < 10) {
        cout << " ";
      }
      cout << r << ": ";

      // move right
      print_spaces((n - r) * width / 2);

      for (int c = 1; c <= r; c++) {
        int value = tri.get(r, c);
        print_spaces(width - count_digits(value));
        cout << value;
      }

      cout << "\n";
    }
  }

  // Exercise 10
  // print star if the number is not divisible by m and a space if it is
  void print(int m) {
    for (int r = 1; r <= n; r++) {

      print_spaces(n - r);

      for (int c = 1; c <= r; c++) {
        if (tri.get(r, c) % m != 0)
          cout << "* ";
        else
          cout << "  ";
      }

      cout << "\n";
    }
  }
};   // <- ends Pascal


int main() {
  Pascal pascal(10);

  pascal.print();

  cout << "\nmod 2:\n";
  pascal.print(2);

  cout << "\nmod 3:\n";
  pascal.print(3);

  return 0;
}  
  
  
  
