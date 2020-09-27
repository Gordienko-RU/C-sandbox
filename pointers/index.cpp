#include <iostream>

using namespace std;

void changeName(string* name) {
  cout << "name address is: " << name << endl;
  cout << "original name by pointer is: " << *name << endl;

  *name = "Vladislav"; 
};

int main() {
  string name = "Vladimir";

  changeName(&name);

  cout << "value after mutation is: " << name << endl;

  return 0;
}

