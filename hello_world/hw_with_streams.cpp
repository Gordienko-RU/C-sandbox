#include <iostream>

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

  return 0;
}
