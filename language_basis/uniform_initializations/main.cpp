#include <iostream>

using namespace std;

class A {
  public:
  int x;

  A() {
    x = 0;
  };
};

int main() {
  // NOTE: Old ways to initialize.
  int i;
  int z = 4.5; // NOTE: that's ok, value will be decreased to appropriate
  int q = 10;
  int k(10);
  int l[] = { 1, 2, 3 };
  A a;
  A a1 = a;

  // NOTE: Uniform initialization.
  int j {};
  int y {4.5}; // NOTE: narrowing not allowed, error
  int n = {10};
  int s {10};
  int h[]{ 1, 2, 3 };
  A b{};
  A b1{b};

  return 0;
}
