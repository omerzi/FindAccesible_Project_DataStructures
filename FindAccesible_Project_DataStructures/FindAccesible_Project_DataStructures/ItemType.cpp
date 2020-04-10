#include "ItemType.h"

ItemType::ItemType(int headComputerIndex,  int line)
{
	this->headComputerIndex = headComputerIndex;
	this->line = line;
}

int ItemType::getLine() const
{
	return this->line;
}

int ItemType::getCompIndex() const
{
	return this->headComputerIndex;
}

void ItemType::setLine(int line)
{
	this->line = line;
}

void ItemType::setAll(int headComputerIndex, int line)
{
	this->headComputerIndex = headComputerIndex;

	this->line = line;
}
