#include <iostream>

using namespace std;

int main() {
  char c = 127;

  cout << (int)c << endl; // 127

  c++;

  cout << (int)c << endl; // -128

  return 0;
}
