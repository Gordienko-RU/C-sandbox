#include <iostream>

using namespace std;

template<typename A>
void changeValue(A && val) {
  val = 3;
}

int main() {
  int i = 56;
  changeValue(i);

  cout << 'i - ' << i << endl;

  return 0;
}
