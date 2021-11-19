#include <iostream>
#include <map>

using namespace std;

class Custom {
  private:
    int val;
  
  public:
  Custom(): val(0) {};
  Custom(int val): val(val) {};
};

int main() {
  map<string, Custom> mapInstance;

  mapInstance["first"]; // default constructor present, so that's ok

  return 0;
}
