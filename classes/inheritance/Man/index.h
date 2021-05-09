#ifndef MAN
#define MAN

#include <string>
#include <iostream>

using namespace std;

class Man {
  private:
    string name;
  public:
    Man(string name) { this->name = name; };
    void sayName() const { cout << this->name << endl; };
};

#endif

