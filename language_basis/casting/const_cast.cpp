#include <iostream>

using namespace std;

void proc(int * pVal) {
  cout << *pVal + 10 << endl;
}

int main() {
  const int test = 5;
  int *rTest = const_cast<int*>(&test); // no errors

  *rTest = 2;
  proc(const_cast<int*>(&test)); // 12 - undefined behavior because of value mutation
  cout << test << endl; // 5 - undefined behavior because of value mutation

  return 0;
}
