#include <iostream>

using namespace std;

int main() {
  string arr[] = { "one", "two", "three" };
  string* pArr = arr;

  cout << "sizeof array pointer " << sizeof(arr) << endl; // 72 bytes
  cout << "sizeof pointer which duplicates array pointer " << sizeof(pArr) << endl; // 8 bytes

  // NOTE: iteration by incrementing
  for (int i = 0; i < 3; i++) {
    cout << *pArr << endl;

    pArr += 1;
  }

  cout << endl;

  // NOTE: traversing a range between two pointers
  string* pBoundaryElement = &arr[2];

  for (string* pElementToProceed = arr; pElementToProceed != pBoundaryElement; pElementToProceed++) {
    cout << *pElementToProceed << endl;
  }

  // NOTE: subtraction of pointers
  const long longArr[] = { 1, 2, 3 };

  const long *firstElement = longArr;
  const long *lastElement = &longArr[2];
  cout << "array length is : " << lastElement - firstElement << endl;

  cout << "size of long type is : " << sizeof(long) << endl;

  return 0;
}
