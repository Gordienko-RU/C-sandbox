#include <iostream>
#include <vector>

using namespace std;

class Action {
  public:
    const int rightOperand;

    Action(int rightOperand): rightOperand(rightOperand) {};
    virtual int operator()(int leftOperand) const =0;
};

class SubtractAction: public Action {
  public:
    SubtractAction(int rightOperand): Action(rightOperand) {};
    int operator()(int leftOperand) const {
      return leftOperand - this->rightOperand;
    };
};

class MultiplyAction: public Action {
  public:
    MultiplyAction(int rightOperand): Action(rightOperand) {};
    int operator()(int leftOperand) const {
      return leftOperand * this->rightOperand;
    };
};

int applyActions(vector<Action*> &actions, const int &target) {
  int resultValue = target;

  for (vector<Action*>::iterator it = actions.begin(); it != actions.end(); ++it) {
    const Action &action = **it;
    resultValue = action(resultValue);
  }

  return resultValue;
};

int main() {
  vector<Action*> actions;

  SubtractAction action1(2);
  MultiplyAction action2(2);

  actions.push_back(&action1);
  actions.push_back(&action2);

  const int target = 5;

  cout << applyActions(actions, target) << endl; // 6

  return 0;
};
