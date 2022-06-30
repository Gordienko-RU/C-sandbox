#include <iostream>

using namespace std;

void fun(int n) {
  if (n > 0) {
    fun(n - 1); // recursive call is the first statement, no work for call phase
    cout << n << endl;
  }
}

void fun1(int n) {
  int i = 0;

  while(i < n) {
    cout << ++i << endl;
  }
}

int main() {
  fun(5); // 1 2 3 4 5

  return 0;
}
