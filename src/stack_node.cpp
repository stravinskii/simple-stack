/*
 * Simple implementation of a STACK to learn and get familiarized with C++.
 *
 * @author: Alan Mauricio García García
 */

#include <iostream>
#include <string>

 using namespace std;

// Struct to use as abstract implementation of the stack core / list
 struct Node
 {
 	int data;
 	struct Node *next;
 };

 typedef struct Node node;

// The abstract implementation of a Stack
 class stack
 {
 public:
 	stack();

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

// Default constructor initializes size as zero and the list
 stack::stack()
 {
 	elements = (node*) malloc(sizeof(node));
 	size = 0;
 }

// Returns the size of the stack
 int stack::getSize()
 {
 	return size;
 }

// Returns true if the stack is empty, false otherwise
 bool stack::isEmpty()
 {
 	if(size >= 1) {
 		return false;
 	} 
 	return true;
 }

// Returns the top element of the stack, but does not removes it
 int stack::peek()
 {
 	if(!isEmpty()) {
 		return elements->data;
 	}
 }

// Pushes a new element into the stack
 void stack::push(int e)
 {
 	node *pushed = (node*) malloc(sizeof(node));
 	pushed->data = e;
 	pushed->next = elements;
 	elements = pushed;
 	size += 1;
 }

// Removes the top element of the stack
 void stack::pop()
 {
 	if(!isEmpty()){
 		node *pop = elements->next;
 		elements = pop;
 		size -= 1;
 	}
 }

// Adds the first (on top) elements of the stack and removes them, also pushes the add onto the stack
 int stack::add()
 {
 	if(getSize() >= 2){
 		int a = peek();
 		pop();

 		int b = peek();
 		pop();

 		int sum = a + b;
 		push(sum);

 		return sum;
 	} else {
 		cout << "error: not enough elements available. - 'add'" << endl;
 	}
 }

// Prints a representation of the stack with each element on a seperate line and element counter
 void stack::print()
 {
 	if(isEmpty()){
 		cout << "[ empty ]" << endl;
 		return;
 	}

 	int count = getSize();
 	node *current = elements;
 	for (int i = 0; i < getSize(); ++i)
 	{
 		cout << "[" << count << "]: " << current->data << endl;
 		current = current->next;
 		count--;
 	}
 }

 int main()
 {
 	cout << "Simple implementation of a C++ Stack." << endl;

 	stack stack;
 	bool prompt = true;
 	while(prompt)
 	{
 		cout << "> ";
 		string args;
 		getline(cin, args);

 		if (args.length() == 1) {
 			switch(args[0]) {
 				case '+': // Add
 				stack.add();
 				cout << "stack peek: " << stack.peek() << endl;
 				break;

 				case 'd': // Print
 				cout << "stack:" << endl;
 				stack.print();
 				break;

 				case 'x': // Exit
 				prompt = false;
 				break;

 				default:
 				cout << "error: invalid argument." << endl;
 			}
 		} else if (args.find("int") != -1) {
 			// Number of arguments verification
 			if(args.find(' ') != args.find_last_of(' ')) {
 				cout << "error: syntax error. - 'int'" << endl; 				
 			} else {
 				string number = args.substr(args.find(' ') + 1);

 				// Not a number verification
 				bool naN = false;
 				string::iterator it = number.begin();
 				while(it != number.end()) {
 					if(!isdigit(*it)) {
 						naN = true;
 						break;
 					} else {
 						++it;
 					}
 				}

				// 'atoi' behavior when MAX_INT is reached begins an offset from MIN_INT
				// it also works the other way around when MIN_INT is reached by 'atoi'
				// therefore using 'atol' is a good way to verify if there was an 'atoi overflow'
 				int n = atoi(number.c_str());
 				long l = atol(number.c_str());
 				
 				if(n < l || n > l){
 					cout << "error: number is too large for <int> value." << endl;
 				} else if(naN) {
 					cout << "error: input is not a number. - 'naN'" << endl;
 				} else {
 					stack.push(n);
 					cout << "Number " << n << " was pushed to the stack." << endl;
 				}
 			}
 		} else {
 			cout << "error: invalid argument." << endl;
 		}
 	}
 }