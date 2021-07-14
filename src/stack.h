// stack.h
#include <list>

// The abstract implementation of a Stack
class Stack {
 public:
  Stack();

  void pop();
  void print();
  void push(int e);
  bool isEmpty();
  int add();
  int peek();
  int getSize();

 private:
  // Variable to keep track of the stack size
  int size;
  // List to implement the stack
  std::list<int> *elements;
};
