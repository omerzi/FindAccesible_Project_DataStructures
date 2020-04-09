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
public: //methods
	int getNextNode();
	int getComputerNumber();
};