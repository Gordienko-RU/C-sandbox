#include <iostream>
#include <list>
#include <fstream>

using namespace std;

class Todo {
  private:
  const string content;
  bool done;

  public:
  Todo(string content): content(content), done(false) {};
  Todo(string content, bool done): content(content), done(done) {};

  string getContent() const {
    return this->content;
  }

  bool isDone() const {
    return this->done;
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

// TODO: add error handling to catch errors while file accessing
class TodoStorage {
  private:
    const string fileName;

  public:
    TodoStorage(): fileName("todos.txt") {};

    void writeTodosToFile(list<Todo> &todos) {
      ofstream writeStream;
      writeStream.open(this->fileName);

      for (list<Todo>::iterator it = todos.begin(); it != todos.end(); it++) {
        writeStream << it->getContent() << endl;
        writeStream << it->isDone() << endl;
      }

      writeStream.close();
    }

    void fillTodosFromFile(list<Todo> &todos) {
      ifstream readStream;
      readStream.open(this->fileName);

      while(readStream.good()) {
        string content;
        string doneStringified;

        getline(readStream, content);
        getline(readStream, doneStringified);

        if (content.empty()) {
          continue;
        }

        bool done = doneStringified == "1";
        Todo todo(content, done);
        todos.push_back(todo);
      }

      readStream.close();
    }
};

void outputTodos(list<Todo> &todos) {
  if (todos.size()) {
    cout << "Current items are:" << endl;

    list<Todo>::iterator it = todos.begin();

    for (int i = 0; it != todos.end(); i++) {
      cout << i << ". " << it->getContent() << " " << it->isDone() << endl;
      ++it;
    }
  } else {
    cout << "You have no items at the moment." << endl;
  }
}

int main() {
  // TODO: to much stuff here, should be splitted to precedures or classes
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

  TodoStorage todoStorage;

  // TODO: implement logic for list reading from binary file
  list<Todo> todos;
  todoStorage.fillTodosFromFile(todos);
  outputTodos(todos);

  // TODO: move program handling to separate class
  while(programRunning) {
    cout << "Enter a command code:" << endl;
    cin >> lastEnteredCommandCode;

    if (lastEnteredCommandCode == ADD_COMMAND.getCode()) {
      string value;
      cin >> value;
      Todo todo(value);
      todos.push_back(todo);

      outputTodos(todos);
      todoStorage.writeTodosToFile(todos);
    }

    if (lastEnteredCommandCode == DELETE_COMMAND.getCode()) {
      int index;
      cin >> index;

      list<Todo>::iterator it = todos.begin();
      int i = 0;

      while (it != todos.end()) {
        if (i == index) {
          it = todos.erase(it);
        } else {
          ++it;
        }

        ++i;
      }

      outputTodos(todos);
      todoStorage.writeTodosToFile(todos);
    }

    if (lastEnteredCommandCode == DONE_COMMAND.getCode()) {
      int index;
      cin >> index;

      list<Todo>::iterator it = todos.begin();
      int i = 0;

      while (it != todos.end()) {
        if (i == index) {
          it->markAsDone();
        }

        ++it;
        ++i;
      }

      outputTodos(todos);
      todoStorage.writeTodosToFile(todos);
    }

    if (lastEnteredCommandCode == UNDONE_COMMAND.getCode()) {
      int index;
      cin >> index;

      list<Todo>::iterator it = todos.begin();
      int i = 0;

      while (it != todos.end()) {
        if (i == index) {
          it->markAdUndone();
        }

        ++it;
        ++i;
      }

      outputTodos(todos);
      todoStorage.writeTodosToFile(todos);
    }

    if (lastEnteredCommandCode == EXIT_COMMAND.getCode()) {
      // TODO: implement logic for list writing to binary file
      programRunning = false;
    }
  }

  cout << "Program ended." << endl;

  return 0;
};
