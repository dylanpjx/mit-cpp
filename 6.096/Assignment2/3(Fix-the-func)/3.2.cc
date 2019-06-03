#include <iostream>

void printNum() { std::cout << number; };

int main() {
  int number = 35;
  printNum(number);
  return 0;
}

// Method 1: void printNum(int number) (Preferred because no global var used)
// Method 2: reorder "int number = 35;" above main
