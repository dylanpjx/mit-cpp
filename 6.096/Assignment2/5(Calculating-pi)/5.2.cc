#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  srand(time(0));
  int n, inCircle;
  cin >> n;
  cout << setw(5) << "x" << setw(12) << "y" << setw(10) << "d" << endl;
  for (int i = 0; i < n; ++i) {
    double x = rand() / (double)RAND_MAX;
    double y = rand() / (double)RAND_MAX;
    double d = sqrt(x * x + y * y);
    if (d < 1) {
      ++inCircle;
    }
    cout << fixed << setprecision(8);
    cout << x << " " << y << " " << d << endl;
  }
  cout << inCircle << endl;
  return 0;
}
