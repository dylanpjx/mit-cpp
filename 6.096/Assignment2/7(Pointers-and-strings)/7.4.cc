#include <iostream>
using namespace std;

void swap(int **p1, int **p2) {
  int *buff = *p1;
  *p1 = *p2;
  *p2 = buff;
}

int main() {
  int x = 5, y = 6;
  int *ptr1 = &x, *ptr2 = &y;
  swap(&ptr1, &ptr2);
  cout << *ptr1 << " " << *ptr2;  // Prints "6 5"
}
