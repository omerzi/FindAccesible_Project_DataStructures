#include "Static_List.h"

class ComputersNetwork
{
private: // members:
	StaticList* networkArray;
	int networkArray_size;
	
public: // constructors:
	ComputersNetwork(int size);
	~ComputersNetwork();
public: // methods:
	void network_data_input();
	StaticList * FindAccesible_Rec(int headComputerIndex);
	void FindAccesible(int headComputerIndex, StaticList* networkArray, char* colors, StaticList* Accesible_List);
};