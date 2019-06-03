#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  srand(time(0));
  double x = rand() / (double)RAND_MAX;
  double y = rand() / (double)RAND_MAX;
  cout << x << " " << y;
  return 0;
}
