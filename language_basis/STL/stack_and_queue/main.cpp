#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Person {
  private:
    string name;

  public:
    Person(string name): name(name) {
      cout << name << " instance created" << endl;
    };

    Person(const Person &copySource) {
      cout << copySource.name << " instance was copied" << endl;

      this->name = copySource.name;
    }

    ~Person() {
      cout << this->name << " instance was destroyed" << endl;
    }

    string getName() {
      return this->name;
    }
};

int main() {
  stack<Person> personsStack;
  
  cout << endl;
  cout << "stack items creation / copying log: " << endl;
  cout << endl;

  Person john("John");
  Person sue("Sue");

  personsStack.push(john);
  personsStack.push(sue);
  
  cout << endl;
  cout << "stack body log: " << endl;
  cout << endl;

  Person personFromStack = personsStack.top(); // extra copy constructor call
  cout << "last person in stack name is: " << personFromStack.getName() << endl;

  personsStack.pop();

  Person &nextPersonFromStack = personsStack.top(); // no extra copy constructor calls
  cout << "next person in stack name is: " << nextPersonFromStack.getName() << endl;

  queue<Person> personsQueue;
  
  cout << endl;
  cout << "queue items copying log: " << endl;
  cout << endl;

  personsQueue.push(john);
  personsQueue.push(sue);
  
  cout << endl;
  cout << "queue body log: " << endl;
  cout << endl;

  while(personsQueue.size()) {
    cout << "next person in queue is " << personsQueue.front().getName() << endl;
    personsQueue.pop();
  }
  
  cout << endl;
  cout << "items destroing log: " << endl;
  cout << endl;

  return 0;
}
