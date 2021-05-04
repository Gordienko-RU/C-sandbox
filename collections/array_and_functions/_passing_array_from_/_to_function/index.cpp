#include <iostream>

using namespace std;

void passByReferense1(int arr[]) {
  cout << sizeof(arr) << endl; // size of pointer would be logged
}

void passByReferense2(int* arr) { // the same as previous example, but with different syntax
  cout << sizeof(arr) << endl; // size of pointer would be logged
}

void passByReferense3(int (&arr)[4]) { // reference to array pointer would be passed, so we can read size
  cout << sizeof(arr) << endl; // size of array would be logged
}

// To avoid using ugly reference syntax we can pass count of elements as arg
void passByReferense4(int* arr, int elementsAmount) {
  cout << sizeof(int) * elementsAmount << endl; // size of array would be logged
  /*...*/
}

int * getArray() {
  int arr[] = { 1, 2, 3 };

  return arr;
}

int * getOnHeapAllocatedArray() {
  int *pMem = new int[3];

  pMem[0] = 1;
  pMem[1] = 2;
  pMem[2] = 3;

  return pMem;
}

int main() {
  int testArr[] = { 1, 2, 3, 4 };

  passByReferense1(testArr);
  passByReferense2(testArr);
  passByReferense3(testArr);
  passByReferense4(testArr, 4);

  int *pArr1 = getArray();
  cout << "element: " << *pArr1 << endl; // garbage value logged

  int *pArr2 = getOnHeapAllocatedArray();
  cout << "element: " << *pArr2 << endl; // worked, but need to clear it
  delete pArr2;

  return 0;
}
