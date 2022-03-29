#include <iostream>
#include <functional>
#include <sstream>

using namespace std;
using namespace placeholders;

string getCarLabel(string mark, string model) {
  stringstream ss;
  ss << mark << " " << model;

  return ss.str();
}

int main() {
  function<string(string)> getMazdaLabel = bind(getCarLabel, "Mazda", _1);
  cout << getMazdaLabel("Tribute") << endl; // Mazda Tribute
  cout << getMazdaLabel("CX-5") << endl; // Mazda CX-5

  return 0;
}

