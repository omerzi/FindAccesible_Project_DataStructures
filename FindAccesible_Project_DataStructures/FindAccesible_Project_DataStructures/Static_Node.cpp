#include "Static_Node.h"
//Constructor:
StaticNode::StaticNode(int value, int nextNode)
{
	this->computerNumber = value;
	this->nextNode = nextNode;
}

StaticNode::~StaticNode()
{
}


int StaticNode::getNextNode()
{
	return this->nextNode;
}

int StaticNode::getComputerNumber()
{
	return this->computerNumber;
}
