// main.cpp
#include <iostream>
#include <string>

#include "stack_node.h"

using namespace std;

int main() {
  cout << "Simple implementation of a C++ Stack." << endl;

  const string usage =
      "Usage:\n"
      "  add <number> - Adds number to the stack.\n"
      "  sum - Sums last two numbers from the stack.\n"
      "  print - Prints current stack.\n"
      "  exit - Exit.";

  cout << usage << endl;

  Stack stack;

  while (true) {
    cout << "> ";
    string command;
    getline(cin, command);

    if (command == "exit") break;

    if (command == "pop") {
      stack.pop();
      stack.print();
      continue;
    }

    if (command == "sum") {
      stack.add();
      stack.print();
      continue;
    }

    if (command == "print") {  // Print
      stack.print();
      continue;
    }

    if (command.find("add") == 0) {  // Add
      // Number of arguments verification
      if (command.find(' ') != command.find_last_of(' ')) {
        cout << "error: syntax error. - 'int'" << endl;
      } else {
        string number = command.substr(command.find(' ') + 1);

        // Not a number verification
        bool naN = false;
        string::iterator it = number.begin();
        while (it != number.end()) {
          if (!isdigit(*it)) {
            naN = true;
            break;
          } else {
            ++it;
          }
        }

        // 'atoi' behavior when MAX_INT is reached begins an offset from MIN_INT
        // it also works the other way around when MIN_INT is reached by 'atoi'
        // therefore using 'atol' is a good way to verify if there was an 'atoi
        // overflow'
        int n = atoi(number.c_str());
        long l = atol(number.c_str());

        if (n < l || n > l) {
          cout << "error: number is too large for <int> value." << endl;
        } else if (naN) {
          cout << "error: input is not a number. - 'naN'" << endl;
        } else {
          stack.push(n);
          stack.print();
        }
      }

      continue;
    }

    cout << "error: invalid argument." << endl;
  }
}
