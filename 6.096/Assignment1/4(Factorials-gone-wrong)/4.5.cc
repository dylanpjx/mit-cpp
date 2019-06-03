#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  switch (N) {
  case 0:
  case 1:
    cout << "1";
    break;
  case 2:
    cout << "2";
    break;
  case 3:
    cout << "6";
    break;
  case 4:
    cout << "24";
    break;
  case 5:
    cout << "120";
    break;
  case 6:
    cout << "720";
    break;
  case 7:
    cout << "5040";
    break;
  case 8:
    cout << "40 320";
    break;
  case 9:
    cout << "362 880";
    break;
  case 10:
    cout << "3 628 880";
    break;
  default:
    cout << "Error!";
    break;
  }
  return 0;
}
