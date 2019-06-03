#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

double piCalc(int n) {
  int inCircle;
  double pi;
  for (int i = 0; i < n; ++i) {
    double x = rand() / (double)RAND_MAX;
    double y = rand() / (double)RAND_MAX;
    double d = sqrt(x * x + y * y);
    if (d < 1) {
      ++inCircle;
    }
  }
  pi = 4 * (inCircle / (double)n);
  return pi;
}

int main() {
  srand(time(0));
  int n, inCircle;
  cin >> n;
  cout << piCalc(n) << endl;
  return 0;
}
