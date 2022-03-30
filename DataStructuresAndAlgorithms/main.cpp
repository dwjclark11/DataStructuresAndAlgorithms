

#include <iostream>
#include "Graphs/Graph_Techniques.h"

int main()
{
	//int G[][8] = { {I, I, I, I, I, I, I, I},
	//			   {I, I, 25, I, I, I, 5, I},
	//			   {I, 25, I, 12, I, I, I, 10},
	//			   {I, I, 12, I, 8, I, I, I},
	//			   {I, I, I, 8, I, 16, I, 14},
	//			   {I, I, I, I, 16, I, 20, 18},
	//			   {I, 5, I, I, I, 20, I, I},
	//			   {I, I, 10, I, 14, 18, I, I} };

	//		
	//Prims(G, 7);

	int Edges[3][9] = {
						{1, 1, 2, 2, 3, 4, 4, 5, 5},
						{2, 6, 3, 7, 4, 5, 7, 6, 7},
						{25, 5, 12, 10, 8, 16, 14, 20, 18} };

	Kruskals(Edges, 7);

	return 0;
} 