#include <iostream>

using namespace std;

void changeName(string* name) {
  cout << "name address is: " << name << endl;
  cout << "original name by pointer is: " << *name << endl;

  *name = "Vladislav"; 
};

string * getPointerToLocalVariable() {
  string name = "Serega";
  string *pName = &name;

  return pName;
}

int main() {
  string name = "Vladimir";

  changeName(&name);

  cout << "value after mutation is: " << name << endl;

  cout << "local value from function: " << *(getPointerToLocalVariable()) << endl; // garbage value

  return 0;
}

