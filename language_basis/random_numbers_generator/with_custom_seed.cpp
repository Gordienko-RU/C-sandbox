#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[])
{
  srand(time(0));

  /*
    NOTE: Seed will be different each time when program running.
  */
  for(int i = 0; i < 4; i++) {
    cout << rand() << endl;
  }

  return 0;
}
