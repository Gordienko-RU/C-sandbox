#include <iostream>

using namespace std;

int main() {
  cout << "Playing with character representation:" << endl;

  char character1 = '4';

  cout << (int)character1 << endl;

  int number1 = 52;

  cout << (char)number1 << endl;

  cout << "Playing with boolean representation:" << endl;

  bool boolean1 = true;

  bool numberAndBooleanAreEqual = boolean1 == 1;

  cout << "boolean1: " << boolean1 << endl; // true(e.g. 1)

  cout << "numberAndBooleanAreEqual: " << numberAndBooleanAreEqual << endl;
}
