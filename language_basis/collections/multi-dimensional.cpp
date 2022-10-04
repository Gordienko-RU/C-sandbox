#include <iostream>
#include <iterator>

using namespace std;

const int * getPlainArray(const int size) {
  const int * arrayPointer = new int[size];

  return arrayPointer;
}

int ** getTwoDimensionalArray(const int amountOfRows, const int amountOfColumns) {
  int ** rowsPointer = new int*[amountOfRows];

  for (int i = 0; i < amountOfRows; ++i) {
    rowsPointer[i] = new int[amountOfColumns];
  }

  return rowsPointer;
}

int main() {
  const int * arrayPointer = getPlainArray(5);

  cout << "plain array pointer: " << sizeof(arrayPointer) << endl;

  int ** twoDimensionalArrayPointer = getTwoDimensionalArray(3, 5);

  cout << "multi array pointer: " << sizeof(twoDimensionalArrayPointer) << endl;

  return 0;
}
