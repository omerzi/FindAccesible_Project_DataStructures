#include "Stack.h"
// Consturctor :
Stack::Stack()
{
	this->top = nullptr;
}

//Destructor:
Stack::~Stack()
{
	MakeEmpty();
}

// MakeEmpty method, deleting all Stack's memory and data :
void Stack::MakeEmpty()
{
	Node* tempNode;
	while (this->top != nullptr)
	{
		tempNode = this->top;
		this->top = this->top->nextNode;
		delete tempNode; 
	}
}

//IsEmpty method : Return true if the stack is empty, return false otherwise:
bool Stack::isEmpty()
{
	if (this->top == nullptr)
		return true;
	return false;
}

//Push method : Pushing an item to the top of the stack 
void Stack::Push(Type i_item)
{
	this->top = new Node(i_item,this->top);
}

//Pop method : return the node in the top of the stack, return nullptr if empty
Type Stack::Pop()
{
	if (!isEmpty())
	{
		Node* tempNode = this->top;
		Type item = this->top->value;
		this->top = this->top->nextNode;
		delete tempNode;
		return item;
	}
}

//top method : return the top of the stack
Node * Stack::Top()
{
	return this->top;
}

