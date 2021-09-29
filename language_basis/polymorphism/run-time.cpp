#include <iostream>
#include <string.h>

using namespace std;

class A {
  public:
    void log() {
      cout << "Base class" << endl;
    }
};

class B: public A {
  public:
    void log() {
      cout << "Derived class" << endl;
    }
};

int main() {
  A baseClassInstance;
  A * baseClassInstancePointer = new B();
  B derivedClassInstance;

  baseClassInstance.log(); // Base class
  derivedClassInstance.log(); // Derived class
  baseClassInstancePointer->log(); // Base class

  return 0;
}

