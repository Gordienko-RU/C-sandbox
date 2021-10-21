#include <iostream>
#include <string.h>

using namespace std;

class A {
  public:
    void virtual log() = 0; // pure virtual function
};

class B: public A {
  public:
    void log() {
      cout << "Derived class B" << endl;
    }
};

class C: public A {
  public:
    void log() {
      cout << "Derived class C" << endl;
    }
};

int main() {
  // pointers
  B b; C c; B * bP = new B;
  A* arr[] = { &b, &c, bP };

  for (int i = 0; i < 3; i++) {
    arr[i]->log();
  }
  /*
    Derived class B
    Derived class C
    Derived class B
  */

  // references
  A &ref = b;
  ref.log();
  // Derived class B

  return 0;
}
