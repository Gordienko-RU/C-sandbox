#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  /*
    NOTE: It will generate the same sequence on each run, since
    default seed is 1 all the time.
  */
  for(int i = 0; i < 4; i++) {
    cout << rand() << endl;
  }

  return 0;
}
