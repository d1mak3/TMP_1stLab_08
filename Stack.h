#ifndef STACK_H
#define STACK_H

#include <vector> // stl class

using namespace std; // due to vector is in std namespace

class Stack
{
private:
	vector<int> _stack; // Default array, but better (to save data)
public:
	int size(); // Size of stack
	int pop(); // Get last element of the stack and delete it
	int back(); // Get last element of the stack
	void push(int); // Add elements in stack
};

#endif // STACK_H

