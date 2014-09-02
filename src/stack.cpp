/*
 * Simple implementation of a STACK to learn and get familiarized with C++.
 *
 * @author: Alan Mauricio García García
 */

#include <iostream>
#include <list>
#include <string>

 using namespace std;

// The abstract implementation of a Stack
 class Stack
 {
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
 	list<int> *elements;
 };

// Default constructor initializes size as zero and the list
 Stack::Stack()
 {
 	size = 0;
 	elements = new list<int>;
 }

// Returns the size of the stack
 int Stack::getSize()
 {
 	return size;
 }

// Returns true if the stack is empty, false otherwise
 bool Stack::isEmpty()
 {
 	if(getSize() >= 1) {
 		return false;
 	} 
 	return true;
 }

// Returns the top element of the stack, but does not removes it
 int Stack::peek()
 {
 	if(!isEmpty()) {
 		return elements->front();
 	}
 }

// Pushes a new element into the stack
 void Stack::push(int e)
 {
 	elements->push_front(e);
 	size += 1;
 }

// Removes the top element of the stack
 void Stack::pop()
 {
 	if(!isEmpty()){
 		elements->pop_front();
 		size -= 1;
 	}
 }

// Adds the first (on top) elements of the stack and removes them, also pushes the add onto the stack
 int Stack::add()
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
 void Stack::print()
 {
 	if(isEmpty()){
 		cout << "[ empty ]" << endl;
 		return;
 	}

 	int i = getSize();
 	for (list<int>::iterator it = elements->begin(); it != elements->end(); ++it)
 	{
 		cout << "[" << i << "]: " << *it << endl;
 		i--;
 	}
 }

 int main()
 {
 	cout << "Simple implementation of a C++ Stack." << endl;

 	Stack stack;
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
 				cout << "Stack peek: " << stack.peek() << endl;
 				break;

 				case 'd': // Print
 				cout << "Stack:" << endl;
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