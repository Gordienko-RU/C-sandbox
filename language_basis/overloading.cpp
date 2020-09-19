#include <iostream>

using namespace std;

void logPersonInfo ();
void logPersonInfo (string name);
void logPersonInfo (string name, int age);
void logPersonInfo (string name, int age, string gender);

int main() {
  logPersonInfo();

  string name = "Jhon";

  logPersonInfo(name);

  int age = 26;

  logPersonInfo(name, age);

  string gender = "male";

  logPersonInfo(name, age, gender);

  return 0;
};

void logPersonInfo () {
  cout << "No info for such person" << endl;
};

void logPersonInfo (string name) {
  cout << "The person name is: " << name << endl;
};

void logPersonInfo (string name, int age) {
  cout << "The person name is: " << name << " and age is: " << age << endl;
};

void logPersonInfo (string name, int age, string gender) {
  cout << "The person name is: " << name << " and age is: " << age;
  cout << "And also - it's gender is: " << gender << endl;
};

