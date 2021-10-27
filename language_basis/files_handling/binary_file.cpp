#include <iostream>
#include <fstream>

#pragma pack(push, 1)
struct S2 {
  int a;
  int b;
  char c;
  int d;

  S2() {};
  S2(int a, int b, char c, int d): a(a), b(b), c(c), d(d) {};
};
#pragma pack(pop)

using namespace std;

int main() {
  S2 * s2Source = new S2(1, 1, 's', 1);

  // writing
  const string fileName = "binary.bin";
  ofstream outputStream;

  outputStream.open(fileName, ios::binary);

  if (!outputStream.is_open()) {
    return 0;
  }

  outputStream.write((char *) s2Source, sizeof(S2));
  outputStream.close();

  // reading
  S2 * s2Target = new S2();

  ifstream inputStream;
  inputStream.open(fileName, ios::binary);

  if (!inputStream.is_open()) {
    return 0;
  }

  inputStream.read((char *) s2Target, sizeof(S2));
  inputStream.close();

  cout << "Readed from file values:" << endl;
  cout << "a:" << s2Target->a << endl;
  cout << "b:" << s2Target->b << endl;
  cout << "c:" << s2Target->c << endl;
  cout << "d:" << s2Target->d << endl;

  return 0;
}
