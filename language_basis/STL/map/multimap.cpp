#include <iostream>
#include <map>

using namespace std;

int main() {
  multimap<string, double> incomeByDate;

  incomeByDate.insert(make_pair("11.11.2020", 2000.3));
  incomeByDate.insert(make_pair("11.11.2020", 100));
  incomeByDate.insert(make_pair("12.11.2020", 989.23));

  for (multimap<string, double>::iterator it = incomeByDate.begin(); it != incomeByDate.end(); ++it) {
    cout << it->first << " : " << it->second << endl;
  }

  pair<multimap<string, double>::iterator, multimap<string, double>::iterator> range =
    incomeByDate.equal_range("11.11.2020");

  cout << endl;
  cout << "range: " << endl;

  for (multimap<string, double>::iterator it = range.first; it != range.second; ++it) {
    cout << it->first << " : " << it->second << endl;
  }

  return 0;
}
