// stack_node.cpp
#include <iostream>
#include "stack_node.h"

// Struct to use as abstract implementation of the stack core / list
struct Node {
  int data;
  struct Node *next;
};

// Default constructor initializes size as zero and the list
Stack::Stack() {
  elements = (node *)malloc(sizeof(node));
  size = 0;
}

// Returns the size of the stack
int Stack::getSize() { return size; }

// Returns true if the stack is empty, false otherwise
bool Stack::isEmpty() {
  if (size >= 1) {
    return false;
  }
  return true;
}

// Returns the top element of the stack, but does not removes it
int Stack::peek() {
  if (!isEmpty()) {
    return elements->data;
  }

  return -999;
}

// Pushes a new element into the stack
void Stack::push(int e) {
  node *pushed = (node *)malloc(sizeof(node));
  pushed->data = e;
  pushed->next = elements;
  elements = pushed;
  size += 1;
}

// Removes the top element of the stack
void Stack::pop() {
  if (!isEmpty()) {
    node *pop = elements->next;
    elements = pop;
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

  int count = getSize();
  node *current = elements;
  for (int i = 0; i < getSize(); ++i) {
    std::cout << "[" << count << "]: " << current->data << std::endl;
    current = current->next;
    count--;
  }
}
