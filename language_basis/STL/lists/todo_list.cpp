#include <iostream>
#include <list>

using namespace std;

class Todo {
  private:
  const string content;
  bool done;

  public:
  Todo(string content): content(content), done(false) {};

  string getContent() const {
    return this->content;
  }

  void markAsDone() {
    this->done = true;
  }

  void markAdUndone() {
    this->done = false;
  }
};

class Command {
  private:
  const string label;
  const int code;

  public:
  Command(string label, int code): label(label), code(code) {};

  string getLabel() const {
    return this->label;
  }

  int getCode() const {
    return this->code;
  }
};

int main() {
  const Command ADD_COMMAND("ADD", 0);
  const Command DELETE_COMMAND("DELETE", 1);
  const Command DONE_COMMAND ("DONE", 2);
  const Command UNDONE_COMMAND("UNDONE", 3);
  const Command EXIT_COMMAND("EXIT", 4);

  const Command COMMANDS[] = { ADD_COMMAND, DELETE_COMMAND, DONE_COMMAND, UNDONE_COMMAND, EXIT_COMMAND };
  const int COMMANDS_AMOUNT = sizeof(COMMANDS) / sizeof(Command);

  cout << "TODO LIST APP" << endl;
  cout << "command list:" << endl;

  for (int i = 0; i < COMMANDS_AMOUNT; i++) {
    const Command command = COMMANDS[i];
    cout << i << " - " << command.getLabel() << endl;
  }

  bool programRunning = true;
  int lastEnteredCommandCode;

  while(programRunning) {
    cout << "Enter a command code:" << endl;
    cin >> lastEnteredCommandCode;

    if (lastEnteredCommandCode == ADD_COMMAND.getCode()) {
    }

    if (lastEnteredCommandCode == DELETE_COMMAND.getCode()) {
    }

    if (lastEnteredCommandCode == DONE_COMMAND.getCode()) {
    }

    if (lastEnteredCommandCode == UNDONE_COMMAND.getCode()) {
    }

    if (lastEnteredCommandCode == EXIT_COMMAND.getCode()) {
      programRunning = false;
    }
  }

  cout << "Program ended." << endl;

  return 0;
};
