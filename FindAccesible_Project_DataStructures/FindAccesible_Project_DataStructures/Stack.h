#ifndef __STACK_H
#define __STACK_H

#include "Node.h"
class Stack
{
private: //members:
	Node* top;//Points to the top of the stack
public: //constructors:
	Stack();
	~Stack();
public: //methods:
	void MakeEmpty();
	bool isEmpty();
	void Push(Type i_item);
	Type Pop();
	Node * Top();
};

#endif