#include <iostream>
#include "./ring.h"

using namespace std;

int main() {
  ring<string> strings(3);

  strings.add("one");
  strings.add("two");
  strings.add("three");
  strings.add("four");

  for (int i = 0; i < strings.size(); ++i) {
    cout << strings.get(i) << endl;
  }

  return 0;
};
