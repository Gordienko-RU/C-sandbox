#include <iostream>

using namespace std;

int fun(int x, int n, int rez = 1) {
  if (n == 1) {
    return (1 + x) * rez;
  }

  const int stepRezult = 1 + x / n;

  return fun(x, n - 1, rez * stepRezult);
}

int fun1(int x, int n) {
  int rez = 1;

  for (int i = 1; i <= n; ++i) {
    rez *= 1 + x / i;
  }

  return rez;
}

int main() {
  cout << fun(2, 3) << endl;
  cout << fun1(2, 3) << endl;

  return 0;
}
