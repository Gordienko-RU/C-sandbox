#include <iostream>
#include <map>

using namespace std;

int main() {
  const int numbers[] = { 1, 2, 3, 4, 5 };

  for (const int number: numbers) {
    cout << number << endl;
  }

  map<string, int> ages;
  ages["John"] = 23;
  ages["Sue"] = 18;

  for (auto agePerName: ages) {
    cout << agePerName.first << ":" << agePerName.second << endl;
  }

  return 0;
}
