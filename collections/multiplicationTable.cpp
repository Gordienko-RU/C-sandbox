#include <iostream>

using namespace std;

void renderHeader() {
    cout << "Multiplication table:" << endl;
};

int main() {
  int multiplicationTable[10][10];

  for(int rowIndex = 0; rowIndex < 10; rowIndex++) {
    for(int columnIndex = 0; columnIndex < 10; columnIndex++) {
      const int numberToMultiply = columnIndex + 1;
      const int multiplier = rowIndex + 1;

      multiplicationTable[rowIndex][columnIndex] = numberToMultiply * multiplier;
    };
  };

  renderHeader();

  // TODO: DRY - move to function or use implemented iterator or array class
    for(int rowIndex = 0; rowIndex < 10; rowIndex++) {
      for(int columnIndex = 0; columnIndex < 10; columnIndex++) {
        cout << " " << multiplicationTable[rowIndex][columnIndex] << " " << flush;
      };

      cout << endl;
    };

    return 0;
}
