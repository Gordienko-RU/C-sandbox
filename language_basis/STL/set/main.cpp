#include <iostream>
#include <set>

using namespace std;

class Example {
  private:
    int val;
  public:
    Example(int val): val(val) {};

    int getValue() const {
      return this->val;
    }

    bool operator<(const Example &example) const {
      return this->val < example.val;
    }
};

int main() {
  // primitive
  set<string> strings;

  strings.insert("first");
  strings.insert("first");
  strings.insert("second");
  strings.insert("third");
  strings.insert("abs");
  /*
    abs
    first
    second
    third
  */

  for (set<string>::iterator it = strings.begin(); it != strings.end(); ++it) {
    cout << *it << endl;
  }

  // object
  set<Example> examples;

  examples.insert(Example(1));
  examples.insert(Example(1));
  examples.insert(Example(3));
  examples.insert(Example(0));

  for (set<Example>::iterator it = examples.begin(); it != examples.end(); ++it) {
    cout << it->getValue() << endl;
  }

  const set<Example>::iterator target = examples.find(0);

  if (target != examples.end()) {
    cout << "founded item value: " << target->getValue() << endl;
  }

  if (examples.count(3)) {
    cout << "element 3 found" << endl;
  }

  return 0;
}
