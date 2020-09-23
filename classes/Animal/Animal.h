#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

using namespace std;

class Animal {
  private:
    string name;
    string sound;
  public:
    Animal();
    Animal(string name, string sound);

    ~Animal();

    void makeSound();

    string getName() { return name; };
    string getSound() { return sound; };

    void setName(string name) { this->name = name; };
    void setSound(string sound) { this->sound = sound; };
};

#endif
