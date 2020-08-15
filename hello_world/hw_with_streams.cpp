#include <iostream>
#include <limits>

using namespace std;

int main() {
  cout << "From RG:" << flush;
  cout << "Hello";
  cout << " ";
  cout << "world";
  cout << ".";
  cout << endl;

  cout << "What is your name, stranger?" << endl;

  string input;

  cin >> input;

  cout << "Your input is: " << input << endl;

  cout << "and some extra - max integer value which can be stored into 'int' type -> ";
  cout << INT_MAX;
  cout << endl;

  return 0;
}
