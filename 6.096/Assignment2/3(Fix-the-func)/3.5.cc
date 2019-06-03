#include <iostream>

int sum(const int x, const int y) { return x + y; }
int main() {
  std::cout << sum(1, 2, 3); // should print 6
  return 0;
}

// Not enough parameters, add a const int z
