#include "Stack.h"
#include <iostream>
#include <vector>

using namespace std;

int Stack::size()
{
	return _stack.size();
}

int Stack::pop()
{
	int pop = _stack.back(); // save value
	_stack.pop_back(); // delete element
	return pop; // return value
}

int Stack::back()
{
	return _stack.back();
}

void Stack::push(int new_num)
{
	_stack.push_back(new_num);
}