#include <iostream>
using namespace std;

int main() {
  int sum, min, max, input, n;
  cin >> n;
  cin >> min;
  max = min;
  sum += min;
  for (int i = 1; i < n; ++i) {
    cin >> input;
    sum += input;
    if (input < min) {
      min = input;
    }
    if (input > max) {
      max = input;
    }
  }
  double mean = sum / n;
  int range = max - min;
  cout << "Mean: " << mean << endl;
  cout << "Max: " << max << endl;
  cout << "Min: " << min << endl;
  cout << "Range: " << range << endl;
  return 0;
}
