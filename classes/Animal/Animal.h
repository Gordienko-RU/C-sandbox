#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

using namespace std;

class Animal {
  private:
    string m_name;
    string m_sound;
  public:
    Animal(string name, string sound);
    ~Animal();

    void makeSound();

    string getName() { return m_name; };
    string getSound() { return m_sound; };

    void setName(string name) { m_name = name; };
    void setSound(string sound) { m_sound = sound; };
};

#endif
