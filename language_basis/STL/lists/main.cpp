#include <iostream>
#include <list>

using namespace std;

int main() {
  list<string> strings(4);
  list<string>::iterator it = strings.begin();

  for (int i = 0; it != strings.end(); i++) {
    *it = "item " + to_string(i);
    ++it;
  }

  it = strings.begin();

  while (it != strings.end()) {
    if (*it == "item 1") {
      strings.insert(it, "inserted string");
    }

    if (*it == "item 3") {
      it = strings.erase(it);
    } else {
      ++it;
    }
  }

  it = strings.begin();

  while (it != strings.end()) {
    cout << *it << endl;
    ++it;
  }

  /*
    item 0
    inserted string
    item 1
    item 2
  */

  return 0;
};
