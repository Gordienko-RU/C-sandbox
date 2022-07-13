#include <iostream>
#include <vector>

using namespace std;

// Time complexity - 3^n
void fun(
  int amountOfDisksToMove, 
  vector<int>& sourceTower, 
  vector<int>& targetTower, 
  vector<int>& tempTower
) {
  switch(amountOfDisksToMove) {
    case 0: {
      return;
    }

    case 1: {
      const int elementToBeMoved = sourceTower.back();
      targetTower.push_back(elementToBeMoved);
      sourceTower.pop_back();

      return;
    }

    case 2: {
      fun(1, sourceTower, tempTower, targetTower);
      fun(1, sourceTower, targetTower, tempTower);
      fun(1, tempTower, targetTower, sourceTower);

      return;
    }

    default: {
      fun(amountOfDisksToMove - 1, sourceTower, tempTower, targetTower);
      fun(1, sourceTower, targetTower, tempTower);
      fun(amountOfDisksToMove - 1, tempTower, targetTower, sourceTower);

      return;
    }
  }
}

int main() {
  vector<int> a = { 1, 2, 3, 4, 5 };
  vector<int> b;
  vector<int> c;

  fun(5, a, c, b);

  cout << "a size " << a.size() << endl;
  cout << "b size " << b.size() << endl;
  cout << "c size " << c.size() << endl;

  return 0;
}
