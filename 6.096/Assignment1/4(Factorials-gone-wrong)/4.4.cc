#include <iostream>

using namespace std;

int main() {
  short number;
  cout << "Enter a number: ";
  cin >> number;
  if (number >= 0) {
    cout << "The factorial of " << number << " is ";
    long long accumulator = 1;
    for (; number > 0; accumulator *= number--)
      ;
    cout << accumulator << ".\n";
  } else {
    cout << "You have entered an erroneous number." << endl;
  }
  return 0;
}
