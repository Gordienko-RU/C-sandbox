#include <iostream>

using namespace std;

int main() {
  cout << "Playing with character representation:" << endl;

  char character1 = '4';

  cout << (int)character1 << endl;

  int number1 = 52;

  // NOTE: since char is number type, we can use any number type to represent character and than cast it
  cout << (char)number1 << endl;

  char characters[] = {'s', 't', 'r', 'i', 'n', 'g'};

  cout << "Array of characters: " << characters << endl;

  cout << "Playing with boolean representation:" << endl;

  bool boolean1 = true;

  bool numberAndBooleanAreEqual = boolean1 == 1;

  cout << "boolean1: " << boolean1 << endl; // true(e.g. 1)

  cout << "numberAndBooleanAreEqual: " << numberAndBooleanAreEqual << endl;
}
