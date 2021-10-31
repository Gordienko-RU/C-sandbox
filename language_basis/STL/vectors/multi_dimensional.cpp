#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector< vector< vector<int> > > numbers(2, vector< vector<int> >(2, vector<int>(2, 5)));
  numbers[0][1].push_back(6);

  for (int x = 0; x < numbers.size(); x++) {
    for (int y = 0; y < numbers[x].size(); y++) {
      for (int z = 0; z < numbers[x][y].size(); z++) {
        cout << numbers[x][y][z] << flush;
      }

      cout << endl;
    }
  }

  /*
    55
    556
    55
    55
  */

  return 0;
};
