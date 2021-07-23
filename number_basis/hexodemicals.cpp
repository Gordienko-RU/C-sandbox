#include <iostream>

using namespace std;

int main() {
  const unsigned int rgba = 0xFFFFFFFF;
  const unsigned char *pOneByte = (unsigned char *) &rgba; 

  cout << "whole value: " << rgba << endl; // 4294967295

  for (int i = 0; i < sizeof(rgba); i++) {
    cout << (int)pOneByte[i] << endl; // 255
  }

  return 0;
}

