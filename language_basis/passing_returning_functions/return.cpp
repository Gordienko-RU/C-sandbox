#include <iostream>
#include <functional>

using namespace std;

int incrementNumber(int numb) {
  return ++numb;
}

int dicrementNumber(int numb) {
  return --numb;
}



function<int(int)> getNumberMutatorByIndex(int index)  {
  switch (index) {
    case 0:
      return &incrementNumber;
    case 1:
      return &dicrementNumber;
    default:
      return incrementNumber;
  }
}

int main() {
  function<int(int)> mutator0 = getNumberMutatorByIndex(0);
  function<int(int)> mutator1 = getNumberMutatorByIndex(1);

  cout << mutator0(2) << endl;
  cout << mutator1(2) << endl;

  return 0;
}
