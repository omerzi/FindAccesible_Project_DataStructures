#ifndef __ITEMTYPE_H
#define	__ITEMTYPE_H
#pragma warning (disable:4996)

#include "Static_List.h"

class ItemType
{
	friend class Stack;
private: // members:
	int headComputerIndex, line;
public://Constructor
	ItemType() = default;
	ItemType(int headComputerIndex, int line);
public://methods:
	int getLine() const;
	int getCompIndex() const;
	void setLine(int line);
	void setAll(int headComputerIndex,int line);
};

#endif