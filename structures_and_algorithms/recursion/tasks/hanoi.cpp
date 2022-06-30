#include <iostream>
#include <vector>

using namespace std;


void fun(vector<int>& a, vector<int>& b, vector<int>& c) {
  const int sizeOfA = a.size();
  const int sizeOfB = b.size();
  const int sizeOfC = c.size();

  const bool allDisksMovedToTargetTower = sizeOfA == 0 && sizeOfB == 0;

  if (allDisksMovedToTargetTower) {
    return;
  }

  
}

int main() {
  // cout << fun(7) << endl;

  return 0;
}
