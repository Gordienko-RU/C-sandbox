#include <iostream>

using namespace std;

// class SomeClass {
//   private:
//     int val;
//   public:
//     SomeClass() {}
//     void setVal(int val) {
//       this->val = val;
//     }
//     void getVal() const {
//       // this->val = 3; // Error.
//       cout << this->val << endl;
//     };
// };

int main() {
  // const SomeClass inst1;
  // inst1.setVal(123); // Error. Call of not const method which lead to mutation.

  // /*
  // const int immutableVariable = 12;
  // immutableVariable = 14; // Error here, since we are using const.

  // const int* pointerToImmutableVariable = &immutableVariable; // Correct pointer.
  // *pointerToImmutableVariable = 14; // Error here, can not change since original variable declared using const.
  
  // int anotherVariable = 15;
  // pointerToImmutableVariable = &anotherVariable; // Since pointer is not constant it's ok.

  // const int* pointerToAnotherVariable = &anotherVariable;
  // *pointerToAnotherVariable = 14; /* Error here, since we declare variable as immutable while
  // pointer creation */

  // /*
  // anotherVariable = 17; // But this is ok.

  // int* const anotherPointerToAnotherVariable = &anotherVariable;
  // *pointerToAnotherVariable = 17;
  
  // int newVariable = 12;
  // pointerToAnotherVariable = &newVariable; // Error here, pointer is constant

  // const int* const imutablePointerToImmutableVariable = &newVariable;
  // *imutablePointerToImmutableVariable = 19; // Error.
  // imutablePointerToImmutableVariable = &anotherVariable; // Error.
  // */

  // SomeClass instance;

  // instance.setVal(145);
  // instance.getVal();



  return 0; 
}
