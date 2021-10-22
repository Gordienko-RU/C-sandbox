#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // writing(creating) file first
  const char* fileName = "test.txt";
  ofstream writeStream;
  writeStream.open(fileName);

  if (!writeStream.is_open()) {
    return 0;
  }

  const int linesAmount = 5;

  for (int i = 0; i < linesAmount; i++) {
    writeStream << "Line number " << i << endl;
  }

  writeStream.close();

  // reading
  ifstream readStream;
  readStream.open(fileName);
  
  if (!readStream.is_open()) {
    return 0;
  }

  string lineContent;

  while(readStream.good()) {
    lineContent += readStream.get();
  }

  readStream.close();

  cout << "File content is: " << endl;
  cout << lineContent << endl;

  return 0;
}
