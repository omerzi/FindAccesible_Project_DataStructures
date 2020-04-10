using namespace std;
#include <iostream>
#include <stdlib.h>
#include "Computers_Network.h"
int main()
{
	int computerNetwork_size,headComputerIndex;
	cout << "Please enter the numbers of computers in the network: " << endl;
	cin >> computerNetwork_size;
	ComputersNetwork network(computerNetwork_size);
	network.network_data_input();
	cout << "Please enter the head computer index: " << endl;
	cin >> headComputerIndex;
	StaticList * list  = network.FindAccesible_Rec(headComputerIndex);
}