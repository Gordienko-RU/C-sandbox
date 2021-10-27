#include <iostream>
#include <fstream>

using namespace std;

struct Entrance {
  string label;
  double value;

  Entrance(string label, double value): label(label), value(value) {};
};

const string separator = " : ";

Entrance * extractEntrance(string line) {
  const int separatorPosition = line.find(separator);
  string label = line.substr(0, separatorPosition);

  const int valueStartPosition = label.length() + separator.length();
  double value = stod(line.substr(valueStartPosition));

  return new Entrance(label, value);
}

string getFormattedLine(Entrance * entrance) {
  return "value for " + entrance->label + " is equal to " + to_string(entrance->value) + "\n";
}

int main() {
  const string fileName = "file.custom";


  ifstream readStream;
  readStream.open(fileName);
  
  if (!readStream.is_open()) {
    return 0;
  }

  string formattedContent;

  while(readStream.good()) {
    string rawLine;
    getline(readStream, rawLine);

    if (rawLine.empty()) {
      continue;
    }

    Entrance * entrance = extractEntrance(rawLine);
    formattedContent += getFormattedLine(entrance);

    delete entrance;
  }

  readStream.close();

  cout << "formatted content: " << endl;
  cout << formattedContent << endl;

  return 0;
}
