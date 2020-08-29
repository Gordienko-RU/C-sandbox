#include <iostream>

// NOTE: UTILS_H_ is kind of unique symbol,
// when file is included in several files there is no need
// to actually include that content each time, so we check
// if symbol was already declared - no need to include it
#ifndef UTILS_H_
#define UTILS_H_

using namespace std;

void renderHeader() {
    cout << "Multiplication table:" << endl;
};

int getTableSize() {
  int size;

  cout << "Enter table size: " << flush;
  cin >> size;

  return size;
}

void renderTable(int size) {
  int multiplicationTable[size][size];

  for(int rowIndex = 0; rowIndex < size; rowIndex++) {
    for(int columnIndex = 0; columnIndex < size; columnIndex++) {
      const int numberToMultiply = columnIndex + 1;
      const int multiplier = rowIndex + 1;

      multiplicationTable[rowIndex][columnIndex] = numberToMultiply * multiplier;
    };
  };

  // TODO: DRY - move to function or use implemented iterator or array class
  for(int rowIndex = 0; rowIndex < size; rowIndex++) {
    for(int columnIndex = 0; columnIndex < size; columnIndex++) {
      cout << " " << multiplicationTable[rowIndex][columnIndex] << " " << flush;
    };

    cout << endl;
  };
}

#endif
