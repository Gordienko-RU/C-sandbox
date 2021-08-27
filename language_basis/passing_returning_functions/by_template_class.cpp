#include <iostream>
#include <functional>

using namespace std;

void printNumber(int numb) {
  cout << "Number is: " << numb << endl;
}

int transformNumber(int numb) {
  return ++numb;
}

void wrapperFunction(
  int numb,
  function<void(int)> printer,
  function<int(int)> transformer
)  {
  const int transformedNumb = transformer(numb);

  printer(transformedNumb);
}

int main() {
  wrapperFunction(1, &printNumber, &transformNumber);

  return 0;
}
