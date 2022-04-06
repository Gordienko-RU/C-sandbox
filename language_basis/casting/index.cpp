#include <iostream>

using namespace std;

int main() {
  const float floatingNumber = 7.7;
  const int implicitlyCoercedToInt = static_cast<int>(floatingNumber);

  cout << "after implicit coercion: " << implicitlyCoercedToInt << endl;

  return 0;
}
