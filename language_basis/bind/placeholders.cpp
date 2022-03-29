#include <iostream>
#include <functional>
#include <sstream>

using namespace std;
using namespace placeholders;

void log(string s1, string s2, string s3) {
  cout << s1 << " ";
  cout << s2 << " ";
  cout << s3 << " ";

  cout << endl;
}

int main() {
  log("first", "second", "third"); // first second third 
  auto changedLog = bind(log, _2, _3, _1);
  changedLog("first", "second", "third"); // second third first 

  return 0;
}

