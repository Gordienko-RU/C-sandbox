#include <iostream>

using namespace std;

int main() {
  const int fullArray[] = { 2, 5, 3, 5 };

  // NOTE: will output address of first element
  cout << "full array: " << fullArray << endl;
  cout << "size of full array: " << sizeof(fullArray) << endl;

  int arrayWithGaps[4];

  arrayWithGaps[0] = 2;
  arrayWithGaps[2] = 3;
  arrayWithGaps[3] = 5;

  cout << "garbage value: " << arrayWithGaps[1] << endl;
  cout << "size of full array: " << sizeof(fullArray) << endl;

  // NOTE: initialize array with values regardless on scope
  int arrayOfZeros[10] = { 0 };

  const int length = sizeof(arrayOfZeros) / sizeof(int);

  for(int i = 0; i < length; i++) {
    cout << "element value: " << arrayOfZeros[i] << endl;
  };

  cout << "Access not allocated memory: " << arrayOfZeros[10] << endl; 

  return 0;
};
