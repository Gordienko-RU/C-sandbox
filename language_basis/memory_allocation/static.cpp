#include <iostream>

using namespace std;

int next() {
  static int counter = 0;

  return counter++;
}

int main() {
  cout << "next value: " << next() << endl;
  cout << "next value: " << next() << endl;
  cout << "next value: " << next() << endl;

  return 0;
}
