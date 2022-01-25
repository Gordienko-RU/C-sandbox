#include <iostream>

#include "./Point.h"

using namespace std;

int main() {
  Point point(2.3, 4.5);

  cout << point + 5 << endl;
  cout << "value returned by index: " << point[0] << endl;

  return 0;
}
