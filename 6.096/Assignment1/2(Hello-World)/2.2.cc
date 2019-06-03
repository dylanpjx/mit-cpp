#include <iostream>
using namespace std;

int main() {
  int n, t;
  cin >> n;
  t = n;
  for (int i = 0; i < n; ++i) {
    cout << "Hello, World!" << endl;
  }
  while (n--) {
    cout << "Hello, World!" << endl;
  }
  do {
    cout << "Hello, World!" << endl;
  } while (t--);
  return 0;
}
