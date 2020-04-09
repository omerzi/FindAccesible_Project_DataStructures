#include "Static_Node.h"
#include <iostream>

#define EMPTY 0;
#define NON_EXIST -1;
using namespace std; 
class StaticList

{
private: //members:
	StaticNode * list;
	int headList; // index of the first node
	int headFree; //index of first free cell
	int tailList;
public: // constructors:
	StaticList() = default;
	StaticList(int array_size);
	~StaticList();
public: // methods:
	void MakeEmpty(int array_size);
	void InsertAfter(int new_node_value, int index_of_node_to_insertAfter); // insert after current node
	void DeleteAfter(int index_of_node_to_deleteAfter); // delete after current node
	bool isEmpty();
	StaticNode* getList();
	int getHeadFree();
	int getHeadList();
	int getTail();
	//Do : all List required functions (find,head....)
};