#if !defined(IT_SPECIALIST)
#define IT_SPECIALIST

#include <string>
#include <iostream>
#include "../Man/index.h"

using namespace std;

class ItSpecialist: public Man {
  private:
    string position;
  public:
    // Since we wanna pass params we should call super-class constructor directly.
    // If no params required - super-class constructor will be called under the hood.
    ItSpecialist(string name, string position): Man(name) {
      this->position = position;
    };
    void sayPosition() const {
      cout << this->position << endl;
    };
};

#endif

// Within class we can call only direct subclass constructor.
// class Machine {
//   public Machine(int number) {
//     ...
//   }
// }

// class Vehicle {
//   public Vehicle(int number): Machine(number) {
//     ...
//   }
// }

// class Car {
//   public Car(int number): Vehicle(number) {
//     ...
//   }
// }
