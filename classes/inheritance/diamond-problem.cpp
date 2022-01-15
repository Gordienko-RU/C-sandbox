#include <iostream>

using namespace std;


class A {
  private:
    int x;
  public:
    A() {};
    A(int x): x(x) {};
    int getX() const { return this->x; };
};

// Wrong inheritance implementation

// class B: public virtual A {
//   private:
//     int y;
//   public:
//     B(int y): A(y), y(y) {};
//     int getY() const { return this->y; };
// };

// class C: public virtual A {
//   private:
//     int z;
//   public:
//     C(int z): A(z), z(z) {};
//     int getZ() const { return this->z; };
// };

// class D: public C, public B {
//   public:
//     D(int z, int y): B(y), C(z) {};
// };

// int main() {
//   D d(10, 20);
//   // error, it's not clear for compiler which instance should be used
//   cout << "x is: " << d.getX() << endl;

//   return 0;
// };

// Correct one

class B: public virtual A {
  private:
    int y;
  public:
    B(int y): y(y) {};
    int getY() const { return this->y; };
};

class C: public virtual A {
  private:
    int z;
  public:
    C(int z): z(z) {};
    int getZ() const { return this->z; };
};

class D: public C, public B {
  public:
    D(int z, int y, int x): A(x), B(y), C(z) {};
};

int main() {
  D d(10, 20, 5);
  cout << "x is: " << d.getX() << endl;

  return 0;
};

