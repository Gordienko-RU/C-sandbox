#include <iostream>

#include "./util.h"

using namespace std;

int main() {
  const int n = 5;

  cout << "sqr of " << n << "is " << util::sqr(n) << endl;

  return 0;
}
