#include <iostream>

using namespace std;

void mutateName(string& nameRef) {
  nameRef = "newName";
}

int main() {
  // In place mutation.
  string name = "Ula";
  string& nameRef = name;

  nameRef = "Hop";

  cout << name << endl; // Hop
  cout << nameRef << endl; // Hop

  // Mutating through function.
  string name1 = "Zula";
  mutateName(name1);

  cout << name1 << endl; // newName
}
