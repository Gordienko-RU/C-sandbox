#include <iostream>

using namespace std;

// tail call optimized version
/*
  time - O(n)
  space - O(1)
*/
int power(int m, int n, int rez = 1, bool rootCall = true) {
  if (n == 0) {
    return rootCall ? 1 : rez;
  }

  if (n == 1 && rootCall) {
    return m;
  }

  return power(m, n - 1, rez * m, false);
}

// no tail optimization
int power1(int m, int n) {
  if (n == 0) {
    return 1;
  }

  return power1(m, n - 1) * m;
}

int main() {
  // cout << power(2, 3) << endl;
  // cout << power(2, 1) << endl;
  // cout << power(2, 0) << endl;

  cout << power1(1, 500000);

  return 0;
}
