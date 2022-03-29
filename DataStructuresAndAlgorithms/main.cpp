

#include <iostream>
#include "Graphs/Graph_Techniques.h"

int main()
{
	int G[7][7] = { {0, 0, 0, 0, 0, 0, 0},
				   {0, 0, 1, 1, 0, 0, 0},
				   {0, 1, 0, 0, 1, 0, 0},
				   {0, 1, 0, 0, 1, 0, 0},
				   {0, 0, 1, 1, 0, 1, 1},
				   {0, 0, 0, 0, 1, 0, 0},
				   {0, 0, 0, 0, 1, 0, 0} };

	DFS<int>(G, 1, 7);

	return 0;
} 