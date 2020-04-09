#include "Static_Node.h"
//Constructor:
StaticNode::StaticNode(int value, int nextNode)
{
	this->computerNumber = value;
	this->nextNode = nextNode;
}

int StaticNode::getNextNode()
{
	return this->nextNode;
}

int StaticNode::getComputerNumber()
{
	return this->computerNumber;
}
