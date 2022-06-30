#include <iostream>

using namespace std;

int fun(int n) {
  if (n > 0) {
    cout << n << endl;
    fun(fun(n - 1));
  }

  return n - 1;
}

/*
  fun(3)
  log(3) -> fun(fun(3 - 1)) -> fun(-3) -> -4
                      |
                    fun(2)
                    log(2) -> fun(fun(2 - 1)) -> fun(-3) -> -3
                                        |
                                      fun(1)
                                      log(1) -> fun(fun(1 - 1)) -> fun(-1) -> -2
                                                          |
                                                        fun(0) -> -1
*/

int main() {
  const int rez = fun(3);
  cout << "rez: " << rez << endl;

  return 0;
}
