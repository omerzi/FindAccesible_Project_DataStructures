#include "Static_List.h"
#pragma warning(disable:4996)

//Constructor:
StaticList::StaticList(int array_size)
{
	MakeEmpty(array_size);// size -1
}

StaticList::~StaticList()
{
	delete this->list;
}

//Initiallizing an empty freelist:
void StaticList::MakeEmpty(int array_size)
{
	this->list = new StaticNode[array_size];
	this->tailList = NON_EXIST;
	this->headList = NON_EXIST;
	this->headFree = EMPTY;
	for (int i = 0; i < array_size - 1; i++)
	{
		this->list[i].nextNode = i + 1;
	}
	this->list[array_size - 1].nextNode = NON_EXIST;
}

//Inserting a value after the given index :
void StaticList::InsertAfter(int new_node_value,int index_of_node_to_insertAfter)
{
	int current_free_cell = this->headFree;  //  saving the index of the cell to insert to
	this->tailList = current_free_cell;//tail update
	this->headFree = this->list[this->headFree].nextNode; // changing the index to the next node to insert to
	this->list[index_of_node_to_insertAfter].nextNode = current_free_cell;
	this->list[current_free_cell].computerNumber = new_node_value;
	this->list[current_free_cell].nextNode = -1;
	if (headList == -1) // list is empty, update list head
	{
		headList = current_free_cell;
	}
}

//Delete a node after a given node index
void StaticList::DeleteAfter(int index_of_node_to_deleteAfter)
{
	int location_toDelete = this->list[index_of_node_to_deleteAfter].nextNode;
	this->list[index_of_node_to_deleteAfter].nextNode = this->list[location_toDelete].nextNode;
	this->list[location_toDelete].computerNumber = NON_EXIST;
	this->list[location_toDelete].nextNode = this->headFree;
	this->headFree = location_toDelete;
}

//Return true if the list is empty, false if its full
bool StaticList::isEmpty()
{
	if (this->headList == -1) //NON-EXIST
		return true;
	return false;
}

StaticNode* StaticList::getList()
{
	return this->list;
}

//return the index of the headFree:
int StaticList::getHeadFree()
{
	return this->headFree;
}

int StaticList::getHeadList()
{
	return this->headList;
}

int StaticList::getTail()
{
	return this->tailList;
}
