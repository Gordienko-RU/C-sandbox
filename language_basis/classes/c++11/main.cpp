#include <iostream>

using namespace std;

class Test {
  public:
    // simplified default member value initialization
    int val = 1;

    // explicitly tells compiler that we want to keep default constructor
    Test() = default;
    Test(int val): val{val} {};
    // protect instance from copying
    Test(const Test & test) = delete;
    // prevent implicit coercion from double to int
    Test(double val) = delete;
};

int main() {
  Test test;
  // Test test1{test}; // error, copy constructor was deleted
  // Test test2(3.5); // error, no implicit coercion, double constructor was deleted

  cout << test.val << endl;
  // cout << test2.val << endl;

  return 0;
};
