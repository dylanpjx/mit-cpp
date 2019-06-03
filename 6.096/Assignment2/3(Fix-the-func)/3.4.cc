#include <cstdlib> //  contains some math functions
#include <iostream>

int difference(const int x, const int y) {
  int diff = abs(x - y); // abs(n) returns absolute value of n
}

int main() {
  std::cout << difference(24, 1238);
  return 0;
}

// int difference has no return val, or use void difference instead
