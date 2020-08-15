#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  float floatNumberWithDecimalPartOverflow = 1.12345678;

  // NOTE: abuse integer part of number, so there is no memory to store decimal part
  float floatNumberWithIntegerPartOverflow = 123456789.12345678;

  cout << "FLOAT:" << endl;
  cout << "size of 'float type'" << sizeof(float) << endl;

  cout << "floatNumberWithDecimalPartOverflow:" << setprecision(20) << fixed;
  cout << floatNumberWithDecimalPartOverflow << endl;

  cout << "floatNumberWithIntegerPartOverflow:" << setprecision(20) << fixed;
  cout << floatNumberWithIntegerPartOverflow << endl;

  return 0;
}
