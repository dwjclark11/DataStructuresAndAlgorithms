#pragma once
#include "../CPP_Style/Queue.h"
#include "../CPP_Style/Stack.h"

/*
	Simple Breadth First Search Function that
	takes a 2D array. A[][7] 7 is assumed for
	testing
*/

template <typename T>
void BFS(T A[][7], int start, int n)
{
	int i = start, j;
	Queue<T> q;

	// This is just a holder that tells us what 
	// vertices have been visited. If 1 visited if
	// 0 not visited
	int visited[7] = { 0 };

	std::cout << i << " ";
	visited[i] = 1;
	q.push_back(i);

	while (!q.isEmpty())
	{
		i = q.pop_front();
		for (j = 1; j < n; j++)
		{
			if (A[i][j] == 1 && visited[j] == 0)
			{
				std::cout << j << " ";
				visited[j] = 1;
				q.push_back(j);
			}
		}
	}
}

/*
	Depth First Search
*/
template <typename T>
void DFS(T A[][7], int start, int n)
{
	static int visited[7] = { 0 };
	int j;

	if (visited[start] == 0)
	{
		std::cout << start << " ";
		visited[start] = 1;

		for (j = 1; j < n; j++)
		{
			if (A[start][j] == 1 && visited[j] == 0)
				DFS(A, j, n);
		}
	}
}