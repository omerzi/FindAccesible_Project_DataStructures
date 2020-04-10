#include "Computers_Network.h"
#define START 1
#define LOOP 2
#define LAST 3
//Constructor:
ComputersNetwork::ComputersNetwork(int size)
{
	this->networkArray_size = size;
	this->networkArray = new StaticList[size+1];//+1 because we are using index 1-size
	for (int i = 0; i < size + 1; i++)
		networkArray[i].MakeEmpty(size-1); // size -1
}

ComputersNetwork::~ComputersNetwork()
{
	delete[] networkArray;
}

//Getting input from the user :
void ComputersNetwork::network_data_input()
{
	int num_of_pairs, computerIndex,computerReceiver;
	cout << "Please enter the number of pairs:" << endl;
	cin >> num_of_pairs;
	cout << "Please enter the pairs:" << endl;
	for (int i = 0; i < num_of_pairs; i++)
	{
		cin >> computerIndex;
		cin >> computerReceiver;
		this->networkArray[computerIndex].InsertAfter(computerReceiver, this->networkArray[computerIndex].getTail());
	}

}
//Find Accesible Recursive function: 
StaticList * ComputersNetwork::FindAccesible_Rec(int headComputerIndex)
{
	char* colors = new char[this->networkArray_size+1];
	StaticList * Accesible_List=new StaticList(this->networkArray_size+1);
	for (int i = 1; i < this->networkArray_size + 1; i++)
	{
		colors[i] = 'w'; //represents "white" color
	}
//	FindAccesible(headComputerIndex, this->networkArray, colors, Accesible_List);
	//Accesible_List->printList();
	FindAccesible_NotRec(headComputerIndex, this->networkArray, colors, Accesible_List);
	Accesible_List->printList();
	delete[] colors;
	return Accesible_List;
}

void ComputersNetwork::FindAccesible(int headComputerIndex, StaticList* networkArray, char* colors, StaticList* Accesible_List)
{
	int headList = networkArray[headComputerIndex].getHeadList();
	colors[headComputerIndex] = 'b';
	Accesible_List->InsertAfter(headComputerIndex, Accesible_List->getTail()); 
	StaticNode current_node = networkArray[headComputerIndex].getList()[headList];
	while (current_node.getNextNode() != -1 && headList != -1)
	{
		if (colors[current_node.getComputerNumber()] == 'w')
		{
			FindAccesible(current_node.getComputerNumber(), networkArray, colors, Accesible_List);
		}
		current_node = networkArray[headComputerIndex].getList()[current_node.getNextNode()];
	}
	if (current_node.getNextNode() == -1) // case for the last element in the list
	{
		if (colors[current_node.getComputerNumber()] == 'w')
		{
			FindAccesible(current_node.getComputerNumber(), networkArray, colors, Accesible_List);
		}
	}
}

void ComputersNetwork::FindAccesible_NotRec(int headComputerIndex, StaticList* networkArray, char* colors, StaticList* Accesible_List)
{
	Stack stack;
	int headList = networkArray[headComputerIndex].getHeadList();
	ItemType current(headComputerIndex, START);
	ItemType next;
	StaticNode list_node = networkArray[headComputerIndex].getList()[headList];
	stack.Push(current);
	while (!stack.isEmpty())
	{
		current = stack.Pop();
		if (current.getLine() == START)
		{
			colors[headComputerIndex] = 'b';
			Accesible_List->InsertAfter(headComputerIndex, Accesible_List->getTail());
			if (headList != -1 && colors[list_node.getComputerNumber()] == 'w')
			{
				current.setLine(LOOP);
				stack.Push(current);
				next.setAll(list_node.getComputerNumber(), START);
				headComputerIndex = list_node.getComputerNumber();
				if (headComputerIndex != -1)
				{
					headList = networkArray[headComputerIndex].getHeadList();
					if (headList != -1)
					{
						list_node = networkArray[headComputerIndex].getList()[headList];
					}
				}
				stack.Push(next);
			}
		}
		else if (current.getLine() == LOOP)
		{
			if (list_node.getNextNode() != -1)
			{
				list_node = networkArray[current.getCompIndex()].getList()[list_node.getNextNode()];
				current.setLine(LAST);
				stack.Push(current);
				next.setAll(list_node.getComputerNumber(), START);
				stack.Push(next);
			}
		}
		else if (current.getLine() == LAST)
		{
			//do nothing
		}
	}
}
