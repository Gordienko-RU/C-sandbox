using namespace std;

int main() {
  int value = 5;

  char *pChar0 = reinterpret_cast<char*>(&value); // ok

  // static_cast from 'int *' to 'char *' is not allowed
  // char *pChar1 = static_cast<char*>(&value);

  return 0;
}
