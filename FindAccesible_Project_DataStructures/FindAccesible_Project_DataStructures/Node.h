#pragma warning (disable:4996)
typedef int Type;

class Node
{
	friend class Stack;
private: // members:
	Type value;
	Node* nextNode;
public: // constructors:
	Node();
	Node(Type value, Node* nextNode = nullptr);
public: // methods:
	void InsertAfter(Node* i_newNode); // insert after current node
	Node* DeleteAfter(); // delete after current node

	
};