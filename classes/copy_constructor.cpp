#include <iostream>

using namespace std;

class Test {
private:
  int field1;
  bool createdByCopyConstructor;
public:
  Test(): createdByCopyConstructor(false) {};
  Test(const Test& copySource): createdByCopyConstructor(true), field1(copySource.field1) {}
  void log() const {
    cout << this->field1 << endl;
  }
  void set(int newValue) {
    this->field1 = newValue;
  }
  void isCopy() {
    cout << this->createdByCopyConstructor << endl;
  }
};

int main() {
  Test inst1;
  inst1.set(34);
  inst1.log();
  inst1.isCopy();

  Test inst2 = inst1; // Implicit copy constructor call through equal operator.
  inst2.log();
  inst2.isCopy();

  Test inst3(inst1); // Direct copy constructor call.
  inst3.log();
  inst3.isCopy();

  return 0;
}
