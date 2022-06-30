#include <iostream>

using namespace std;

// TODO: static variables must be cleared
int fun(int x, int n) {
  static int factorial = 1;
  static int power = 1;

  if (n == 0) {
    return 1;
  }

  int rez = fun(x, n - 1);

  factorial = factorial * n;
  power = power * x;

  return rez + (power / factorial);
}

int main() {
  cout << fun(2, 3);

  return 0;
}
