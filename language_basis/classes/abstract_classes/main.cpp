#include <iostream>

using namespace std;

class Worker {
  public:
    virtual void logName()=0;
    virtual void logSphere()=0;
    virtual void logScope()=0;

    virtual ~Worker() {};
};

class ItWorker: public Worker {
  private:
    string name;
    const string sphere;

  public:
    ItWorker(string name): name(name), sphere("IT") {};

    void logName() {
      cout << this->name << endl;
    };

    void logSphere() {
      cout << this->sphere << endl;
    };
    
    virtual ~ItWorker() {};
};

class FEWorker: public ItWorker {
  private:
    const string scope;

  public:
    FEWorker(string name): ItWorker(name), scope("FE") {};

    void logScope() {
      cout << this->scope << endl;
    };
};

int main() {
  // Worker worker; // Error
  // ItWorker itWorker("Urd"); // Error
  FEWorker feWorker("Urd");
  feWorker.logName();
  feWorker.logSphere();
  feWorker.logScope();

  Worker &workerRef = feWorker;

  cout << "log through ref:" << endl;

  workerRef.logName();
  workerRef.logSphere();
  workerRef.logScope();

  return 0;
}

