#include <iostream>
#include <vector>

using namespace std;

class A {
  public:
  int x;

  A() {
    x = 0;
  }

  A(int x): x{x} {};
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
  // int y{4.5}; // NOTE: narrowing not allowed, error
  int n = {10};
  int s{10};
  int h[]{ 1, 2, 3 };
  A a2{};
  A a3{a2};

  vector<int> numbers {1, 2, 9, 20, 34};

  for (auto numb: numbers) {
    cout << numb << endl;
  }

  A a4{7};

  return 0;
}
