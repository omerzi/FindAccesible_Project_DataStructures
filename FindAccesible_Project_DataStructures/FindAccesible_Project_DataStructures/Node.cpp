#include "Node.h"
// Constructor :
Node::Node()
{
	this->nextNode = nullptr;
}
// Copy Constructor :
Node::Node(Type value, Node* i_nextNode)
{
	this->value = value;
	this->nextNode = i_nextNode;
}
// Insert after current node method:
void Node::InsertAfter(Node* i_newNode)
{
	i_newNode->nextNode = this->nextNode;
	this->nextNode = i_newNode;
}
//Delete node after current node method :
Node* Node::DeleteAfter()
{
	Node* tempNode = this->nextNode;
	if (this->nextNode == nullptr)
	{
		return nullptr;
	}
	this->nextNode = tempNode->nextNode;
	return tempNode;
}
