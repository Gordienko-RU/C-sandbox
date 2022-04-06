#include <iostream>
#include <string>

#include "Animal.h"

using namespace std;

Animal::Animal(string name, string sound) {
  this->name = name;
  this->sound = sound;
};

Animal::~Animal() {
  cout << "Destructurization happened." << endl;
}

void Animal::makeSound() {
  cout << "The sound is: " << sound << endl;
};
