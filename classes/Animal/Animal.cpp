#include <iostream>
#include <string>

#include "Animal.h"

using namespace std;

Animal::Animal(string name, string sound) {
  m_name = name;
  m_sound = sound;
};

void Animal::makeSound() {
  cout << "The sound is: " << m_sound << endl;
};
