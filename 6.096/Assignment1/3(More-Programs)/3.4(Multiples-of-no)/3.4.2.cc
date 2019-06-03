#include <iostream>
using namespace std;

int main() {
  int N;
  while (cin >> N) {
    if (N >= 0 && N % 5 == 0) {
      cout << N / 5 << endl;
    } else {
      continue;
    }
  }
  return 0;
}
