#include <iostream>
#include <sstream>

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

  // NOTE: concatenation
  int numb = '7';
  string message = "my numb is - ";

  stringstream ss;
  ss << message << numb;
  string concatenated = ss.str();
  cout << concatenated << endl;

  string concatenatedWithToString = message + to_string(numb);
  cout << concatenatedWithToString << endl;
}
