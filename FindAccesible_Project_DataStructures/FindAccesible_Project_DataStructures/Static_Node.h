#ifndef __STATICNODE_H
#define __STATICNODE_H

#pragma warning (disable:4996)

class StaticNode
{
	friend class StaticList;
private://members:
	int computerNumber;
	int nextNode;
public: //constructor
	StaticNode() = default;
	StaticNode(int value, int nextNode = -1);
	~StaticNode();
public: //methods
	int getNextNode();
	int getComputerNumber();
};

#endif