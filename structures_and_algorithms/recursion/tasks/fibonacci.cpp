#include <iostream>
#include <map>

using namespace std;

// TODO: static variables must be cleared
int fun(int n) {
  static int firstPreviousNumber = 0;
  static int secondPreviousNumber = 0;

  if (n <= 1) {
    return n;
  }

  const int numberForNStep = fun(n - 1);

  secondPreviousNumber = firstPreviousNumber;
  firstPreviousNumber = numberForNStep;

  return firstPreviousNumber + secondPreviousNumber;
}

int fun1(int n) {
  if (n <= 1) {
    return n;
  }

  int firstPreviousNumber = 1;
  int secondPreviousNumber = 0;
  int rez = 0;

  for (int i = 2; i <= n; ++i) {
    rez = firstPreviousNumber + secondPreviousNumber;

    secondPreviousNumber = firstPreviousNumber;
    firstPreviousNumber = rez;
  }

  return rez;
}

// NOTE: excessive version
int fun2(int n) {
  cout << n << ";";

  if (n <= 1) {
    return n;
  }

  return fun2(n - 1) + fun2(n - 2);
}

map<int, int> cache;

// NOTE: memoized version
int fun3(int n) {
  auto it = cache.find(n);

  if (it != cache.end()) {
    return it->second;
  }

  if (n <= 1) {
    return n;
  }

  int rez = fun3(n - 1) + fun3(n - 2);
  cache[n] = rez;

  return rez;
}

int main() {
  cout << fun(7) << endl;
  cout << fun1(7) << endl;
  cout << "not memoized" << endl;
  cout << fun2(7) << endl;
  cout << "memoized" << endl;
  cout << fun3(7) << endl;
  cout << cache.size() << endl;

  return 0;
}
