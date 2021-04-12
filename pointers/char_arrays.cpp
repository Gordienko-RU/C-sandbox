#include <iostream>

using namespace std;

int main() {
  // NOTE: chars array reversing in place
  char arrayToReverse[] = "123";
  const int lastElementIndex = sizeof(arrayToReverse) - 2; // extra one for \0 symbol
  char* tailPointer = &arrayToReverse[lastElementIndex];
  char* headPointer = arrayToReverse;

  while(true) {
    const char temp = *headPointer;
    *headPointer = *tailPointer;
    *tailPointer = temp;

    if (tailPointer == headPointer) {
      break;
    } else {
      headPointer++;
      tailPointer--;
    };
  }

  cout << "inline reversed char array : " << arrayToReverse << flush;

  cout << endl;

  // char arr1[] = { '1', '2', '3' };
  // cout << sizeof(arr1) << endl; // 3

  // char arr2[] = "123";
  // cout << sizeof(arr2) << endl; // 4

  // char arr4[] = "first\0second\0third";
  // cout << arr4 << endl; // first - traversed till terminator,
  // // and logged because of overloading '<<' for char*

  // cout << "size of splitted array: " << sizeof(arr4) << endl;
  // cout << "counting start:" << endl;

  // // TODO: some undefined behavior happening here
  // for (int i = 0; i < sizeof(arr4); i++) {
  //   cout << arr4[i] << endl;
  //   cout << "index" << i << endl;
  // }

  return 0;
}
