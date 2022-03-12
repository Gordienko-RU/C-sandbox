#include <iostream>

using namespace std;

class B {
  public:
    virtual void log() {
      cout << "Base class" << endl;
    }
};

class D: public B {
  private:
    int x {5};
  public:
    void log() {
      cout << "Derived class" << endl;
    }

    void anotherLog() {
      cout << "Derived class x is: " << this->x << endl;
    }
};

// void log(B * target) {
//   D * pD = static_cast<D*>(target);

//   pD->anotherLog();
// }

// int main() {
//   B b;
//   D d;

//   log(&d); // Derived class x is: 5 - valid case because of Derived -> Parent -> Derived conversion
//   log(&b); // Derived class x is: 226234464 - garbage value because Parent -> Derived - not complete object pointer

//   return 0;
// }

void log(B * target) {
  D * pD = dynamic_cast<D*>(target);

  if (!(pD == nullptr)) {
    pD->anotherLog();
  }

}

int main() {
  B b;
  D d;

  log(&d); // Derived class x is: 5 
  log(&b); // No log because of wrong conversion

  return 0;
}
