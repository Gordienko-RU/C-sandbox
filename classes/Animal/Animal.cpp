#include <iostream>
#include <string>

#include "Animal.h"

using namespace std;

Animal::Animal() {
  m_name = "Not defined";
  m_sound = "Not defined";
};

Animal::Animal(string name, string sound) {
  m_name = name;
  m_sound = sound;
};

Animal::~Animal() {
  cout << "Destructurization happened." << endl;
}

void Animal::makeSound() {
  cout << "The sound is: " << m_sound << endl;
};
