#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  if (x > 1) {
    for (int j = x; j > 2; --j) {
      bool isPrime = true;
      for (int k = 2; k < j; ++k) {
        if (j % k == 0) {
          isPrime = false;
          break;
        }
      }
      if (isPrime) {
        cout << j << endl;
      }
    }
    cout << "2" << endl;
  }
  return 0;
}
