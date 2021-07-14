// stack.cpp
#include <iostream>
#include <list>
#include <string>

#include "stack.h"

// Default constructor initializes size as zero and the list
Stack::Stack() {
  size = 0;
  elements = new std::list<int>;
}

// Returns the size of the stack
int Stack::getSize() { return size; }

// Returns true if the stack is empty, false otherwise
bool Stack::isEmpty() {
  if (getSize() >= 1) {
    return false;
  }
  return true;
}

// Returns the top element of the stack, but does not removes it
int Stack::peek() {
  if (!isEmpty()) {
    return elements->front();
  }

  return -999;
}

// Pushes a new element into the stack
void Stack::push(int e) {
  elements->push_front(e);
  size += 1;
}

// Removes the top element of the stack
void Stack::pop() {
  if (!isEmpty()) {
    elements->pop_front();
    size -= 1;
  }
}

// Adds the first (on top) elements of the stack and removes them, also pushes
// the add onto the stack
int Stack::add() {
  if (getSize() >= 2) {
    int a = peek();
    pop();

    int b = peek();
    pop();

    int sum = a + b;
    push(sum);

    return sum;
  } else {
    std::cout << "error: not enough elements available. - 'add'" << std::endl;
    return -999;
  }
}

// Prints a representation of the stack with each element on a seperate line and
// element counter
void Stack::print() {
  if (isEmpty()) {
    std::cout << "[ empty ]" << std::endl;
    return;
  }

  int i = getSize();
  for (std::list<int>::iterator it = elements->begin(); it != elements->end();
       ++it) {
    std::cout << "[" << i << "]: " << *it << std::endl;
    i--;
  }
}
