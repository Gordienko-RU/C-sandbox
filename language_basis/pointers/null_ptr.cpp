#include <iostream>

using namespace std;

int main() {
  int * pInt = NULL;
  int * pInt1;

  cout << pInt << endl; // 0x0
  cout << pInt1 << endl; // 0x0
  cout << (bool)pInt << endl; // 0
  cout << (bool)pInt1 << endl; // 0

  return 0;
}
