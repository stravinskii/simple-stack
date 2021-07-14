// stack_node.h
typedef struct Node node;

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
  // Node to implement the stack
  node *elements;
};
