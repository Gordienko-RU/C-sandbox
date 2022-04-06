#include <iostream>

using namespace std;

class Test {
  public:
    int a;
    int b;
    int c;

    Test(int a, int b): a{a}, b{b} {};
    Test(int a, int b, int c): Test{a, b} {
      this->c = c;
    };
};

int main() {
  Test test {1, 2, 3};

  cout << test.a << endl; // 1
  cout << test.b << endl; // 2
  cout << test.c << endl; // 3

  return 0;
}
