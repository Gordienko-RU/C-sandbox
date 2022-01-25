#include <iostream>
#include "./ring.h"

using namespace std;

int main() {
  ring<string> strings(3);

  strings.add("one");
  strings.add("two");
  strings.add("three");
  strings.add("four");

  for (string value: strings) {
    cout << "value is: " << value << endl;
  }

  // ring<string>::iterator it = strings.begin();

  // cout << "from iterator: " << endl;
  // cout << *it << endl;
  // ++it;
  // cout << *it << endl;
  // ++it;
  // cout << *it << endl;

  return 0;
};
