#include <iostream>
#include <string>
using namespace std;

string pigLatinify(string s) {
  const string VOWELS = "aeiou";
  if (VOWELS.find(s[0]) != string::npos) {
    s += "-way";
    return s;
  } else if (s.find('q') == 0) {
    return (s.substr(1) + "-" + s.substr(0, 1) + "uay");
  } else {
    return (s.substr(1) + "-" + s.substr(0, 1) + "ay");
  }
}

int main() {
  string s;
  cin >> s;
  cout << pigLatinify(s) << endl;
}
