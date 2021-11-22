#include <iostream>
#include <map>

using namespace std;

class Custom {
  public:
  int val;
  int val1;

  Custom(): val(0), val1(0) {};
  Custom(int val): val(val), val1(0) {};
  Custom(int val, int val1): val(val), val1(val1) {};

  bool operator<(const Custom &instanceToCompareWith) const {
    cout << "comparison triggered with" << instanceToCompareWith.val << endl;

    return instanceToCompareWith.val > this->val;
  }
};

int main() {
  // class instance as a value
  map<string, Custom> mapOfInstance;

  mapOfInstance["first"]; // default constructor present, so that's ok

  // class instance as a key
  map<Custom, string> mapByInstance;

  mapByInstance[Custom(5, 0)] = "first"; // < operator overloading implemented, so we can use instance as a key
  mapByInstance[Custom(5, 4)] = "new";

  /*
    Objects were different, but because of less operator implementation map identifies them as
    equal, and update only value, not a key.
  */
  cout << mapByInstance.find(5)->first.val1 << endl; // 0 - original key value
  cout << mapByInstance.find(5)->second << endl; // "new"

  /*
    Class wrap passed value with matched constructor, and than, using custom
    comparisson operator, define are instances equal, or not.
  */
  if (mapByInstance.find(5) != mapByInstance.end()) {
    cout << "found by instance member" << endl; // logged
  }

  return 0;
}
