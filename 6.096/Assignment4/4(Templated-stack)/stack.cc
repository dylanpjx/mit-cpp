#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack;

template <typename T>
Stack<T> operator+(const Stack<T>& a, const Stack<T>& b) {
  Stack<T> c = a;
  for (auto& j : b.tvec) {
    c.tvec.push_back(j);
  }
  return c;
}

template <class T>
class Stack {
 private:
  vector<T> tvec;

 public:
  friend Stack<T> operator+<>(const Stack<T>& a, const Stack<T>& b);
  bool empty() const { return tvec.empty(); }
  void push(const T& item) { tvec.push_back(item); }
  T& top() { return tvec[tvec.size() - 1]; }
  void pop() { tvec.pop_back(); }
  void print() {
    for (auto i : tvec) {
      cout << i << " ";
    }
    cout << endl;
  }
};

int main() {
  Stack<int> a, b;
  cout << a.empty() << endl;       // test of a is empty, should return true
  for (int i = 1; i <= 10; ++i) {  // a = {1,2, ..., 9, 10}
    a.push(i);
  }
  a.print();                        // test output of a
  a.top();                          // print top of a, output = 10
  for (int j = 11; j <= 20; ++j) {  // b = {11, 12, ..., 19, 20}
    b.push(j);
  }
  a.pop();    // remove top element of a
  a.print();  // test output of a
  b.print();  // test output of b

  Stack<int> c = a + b;  // test operator overloading implementation
  c.print();             // test output of c
}
