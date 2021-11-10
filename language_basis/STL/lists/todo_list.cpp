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
class TodoHandler {
  private:
    const string storageFileName;
    list<Todo> todos;

    void fillTodosFromFile() {
      ifstream readStream;
      readStream.open(this->storageFileName);

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
        this->todos.push_back(todo);
      }

    readStream.close();
  }

  public:
    TodoHandler(): storageFileName("todos.txt") {
      this->fillTodosFromFile();
    };

    // TODO: investigate why references can be used here
    list<Todo> * getTodos() {
      return &this->todos;
    }

    void writeTodosToFile() {
      ofstream writeStream;
      writeStream.open(this->storageFileName);

      for (list<Todo>::iterator it = this->todos.begin(); it != this->todos.end(); it++) {
        writeStream << it->getContent() << endl;
        writeStream << it->isDone() << endl;
      }

      writeStream.close();
    }

    void outputTodos() {
      if (this->todos.size()) {
        cout << "Current items are:" << endl;

        list<Todo>::iterator it = this->todos.begin();

        for (int i = 0; it != this->todos.end(); i++) {
          cout << i << ". " << it->getContent() << " " << it->isDone() << endl;
          ++it;
        }
      } else {
        cout << "You have no items at the moment." << endl;
      }
    }
};

class CommandHandler {
  public:
    const Command ADD_COMMAND;
    const Command DELETE_COMMAND;
    const Command DONE_COMMAND;
    const Command UNDONE_COMMAND;
    const Command EXIT_COMMAND;

    CommandHandler():
      ADD_COMMAND("ADD", 0),
      DELETE_COMMAND("DELETE", 1),
      DONE_COMMAND ("DONE", 2),
      UNDONE_COMMAND("UNDONE", 3),
      EXIT_COMMAND("EXIT", 4) {};

    void logCommands() {
      cout << "command list:" << endl;

      // TODO: is it worth to create collection here?
      cout << 0 << " - " << this->ADD_COMMAND.getLabel() << endl;
      cout << 1 << " - " << this->DELETE_COMMAND.getLabel() << endl;
      cout << 2 << " - " << this->DONE_COMMAND.getLabel() << endl;
      cout << 3 << " - " << this->UNDONE_COMMAND.getLabel() << endl;
      cout << 4 << " - " << this->EXIT_COMMAND.getLabel() << endl;
    }

    void handleAdd(list<Todo> * todos, TodoHandler &todoHandler) {
      string value;
      cin >> value;
      Todo todo(value);
      todos->push_back(todo);

      todoHandler.outputTodos();
      todoHandler.writeTodosToFile();
    }

    void handleDelete(list<Todo> * todos, TodoHandler &todoHandler) {
      int index;
      cin >> index;

      list<Todo>::iterator it = todos->begin();
      int i = 0;

      while (it != todos->end()) {
        if (i == index) {
          it = todos->erase(it);
        } else {
          ++it;
        }

        ++i;
      }

      todoHandler.outputTodos();
      todoHandler.writeTodosToFile();
    }

    void handleDone(list<Todo> * todos, TodoHandler &todoHandler) {
      int index;
      cin >> index;

      list<Todo>::iterator it = todos->begin();
      int i = 0;

      while (it != todos->end()) {
        if (i == index) {
          it->markAsDone();
        }

        ++it;
        ++i;
      }

      todoHandler.outputTodos();
      todoHandler.writeTodosToFile();
    }

    void handleUndone(list<Todo> * todos, TodoHandler &todoHandler) {
      int index;
      cin >> index;

      list<Todo>::iterator it = todos->begin();
      int i = 0;

      while (it != todos->end()) {
        if (i == index) {
          it->markAdUndone();
        }

        ++it;
        ++i;
      }

      todoHandler.outputTodos();
      todoHandler.writeTodosToFile();
    }

    void logEnterIndexMessage() {
      cout << "Enter item index:" << endl;
    }
};

int main() {
  CommandHandler commandHandler;

  cout << "TODO LIST APP" << endl;
  commandHandler.logCommands();

  bool programRunning = true;
  int lastEnteredCommandCode;

  TodoHandler todoHandler;
  todoHandler.outputTodos();
  list<Todo> * todos = todoHandler.getTodos();

  while(programRunning) {
    cout << "Enter a command code:" << endl;
    cin >> lastEnteredCommandCode;

    if (lastEnteredCommandCode == commandHandler.ADD_COMMAND.getCode()) {
      cout << "Enter item content:" << endl;
      commandHandler.handleAdd(todos, todoHandler);
    }

    if (lastEnteredCommandCode == commandHandler.DELETE_COMMAND.getCode()) {
      commandHandler.logEnterIndexMessage();
      commandHandler.handleDelete(todos, todoHandler);
    }

    if (lastEnteredCommandCode == commandHandler.DONE_COMMAND.getCode()) {
      commandHandler.logEnterIndexMessage();
      commandHandler.handleDone(todos, todoHandler);
    }

    if (lastEnteredCommandCode == commandHandler.UNDONE_COMMAND.getCode()) {
      commandHandler.logEnterIndexMessage();
      commandHandler.handleUndone(todos, todoHandler);
    }

    if (lastEnteredCommandCode == commandHandler.EXIT_COMMAND.getCode()) {
      programRunning = false;
    }
  }

  cout << "Program ended." << endl;

  return 0;
};
