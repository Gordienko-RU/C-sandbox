#include <iostream>
#include <string>

#include "Animal/Animal.h"
// TODO: should be done through compiler script
#include "Animal/Animal.cpp"

using namespace std;

Animal kittyFactory(string name) {
  const string sound = "meow";

  return Animal(name, sound);
};

int main() {
  Animal marsikTheKitty = kittyFactory("Marsik");

  cout << "Introduce our new kitty: " << marsikTheKitty.getName() << endl;
  cout << "What it says?" << endl;
  marsikTheKitty.makeSound();

  marsikTheKitty.setName("Voldemar");
  cout << "Renamed kitty name is: " << marsikTheKitty.getName() << endl;

  Animal animal;

  cout << "Introduce our new not init animal: " << animal.getName() << endl;
  cout << "What it says?" << endl;
  animal.makeSound();

  return 0;
};
