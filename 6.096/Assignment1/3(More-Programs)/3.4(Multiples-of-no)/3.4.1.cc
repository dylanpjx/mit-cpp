#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  (N >= 0 && N % 5 == 0) ? cout << N / 5 << endl : cout << "-1" << endl;
}
