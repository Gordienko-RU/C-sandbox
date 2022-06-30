#include <iostream>

using namespace std;

void fun(int n) {
  if (n > 0) {
    cout << n << endl;
    fun(n - 1); // recursive call is the last statement, no work for return phase
  }
}

void fun1(int n) {
  while(n > 0) {
    cout << n << endl;
    --n;
  }
}

int main() {
  fun(5); // 5 4 3 2 1

  return 0;
}
