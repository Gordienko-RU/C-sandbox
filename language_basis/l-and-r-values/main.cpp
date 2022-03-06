#include <iostream>

using namespace std;

int * b;

int * returnLValue() {
  int * i = new int{2};
  b = i;

  return i;
}

int returnRValue() {
  return 4;
}

int getByConstR(const int &test) {
  return test;
}

int main() {
  // it's legal, because function expect const reference, so compiler is able to handle this
  getByConstR(5);

  /*
  function returning RValue, so we can not use it as a left operand of
  assign - no memory location created
  returnRValue() = 4;
  */

  // function returning LValue, so we can use it as left opperand for assignment operation
  returnLValue();
  cout << *b << endl; // 2
  (*returnLValue()) = 4;
  cout << *b << endl; // 4

  // also ok
  int & ref = (*returnLValue());

  /*
    x - LValue
    234 - RValue
  */
  int x = 234;

  /*
    pX - LValue
    &x - produces RValue
  */
  int * pX = &x;

  return 0;
}
