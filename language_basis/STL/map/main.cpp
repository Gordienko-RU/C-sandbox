#include <iostream>
#include <map>

using namespace std;

int main() {
  map<string, bool> marriageStatus;

  marriageStatus["Sam"] = true;
  marriageStatus["Clo"] = false;
  marriageStatus["Zeno"] = true;
  marriageStatus["Dru"]; // NOTE: default value set based on type

  cout << marriageStatus["Clo"] << endl;

  pair<string, bool> handMadePair("Urt", true);
  pair<string, bool> factoryMadePair = make_pair("Zure", false);

  marriageStatus.insert(handMadePair);
  marriageStatus.insert(factoryMadePair);

  for (map<string, bool>::iterator it = marriageStatus.begin(); it != marriageStatus.end(); ++it) {
    cout << it->first << ": " << it->second << endl;

    // pair<string, bool> status = *it;    
    // cout << status.first << ": " << status.second << endl; // NOTE: the same
  }

  if (marriageStatus.find("Dru") != marriageStatus.end()) {
    cout << "Dru found!";
  }

  return 0;
}
