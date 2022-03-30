#pragma once
#include "../CPP_Style/Queue.h"
#include "../CPP_Style/Stack.h"
#define I INT_MAX
#define N 8
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

/*
	Prim's Algorithm/Program
*/

void PrintMST(int T[][N - 2], int Cost[N][N])
{
	std::cout << "Minimum Spanning Tree Edges w/ Cost" << std::endl;
	int sum = 0;

	for (int i = 0; i < N - 2; i++)
	{
		int c = Cost[T[0][i]][T[1][i]];
		std::cout << "[" << T[0][i] << ", " << T[1][i] << "] cost: " << c << std::endl;
		sum += c;
	}

	std::cout << std::endl;
	std::cout << "Total cost: " << sum << std::endl;
}

void PrintMST(int T[][N - 2], int Cost[3][N + 1])
{
	std::cout << "Kruskals Minimum Spanning Tree Edges w/ Cost" << std::endl;
	int sum = 0;

	for (int i = 0; i < N - 2; i++)
	{
		int c = 0;
		for (int j = 0; j < N; j++)
		{
			if (Cost[0][j] == T[0][i] && Cost[1][j] == T[1][i])
			{
				c = Cost[2][j];
				continue;
			}
		}

		std::cout << "[" << T[0][i] << ", " << T[1][i] << "] cost: " << c << std::endl;
		sum += c;
	}

	std::cout << std::endl;
	std::cout << "Total cost: " << sum << std::endl;
}

void Prims(int Cost[][N], int n)
{
	int i, j, k = 0, u = 0, v = 0, min = I;
	int near[N];
	int t[2][N - 2];

	// loop through the 2D array
	for (i = 1; i <= n; i++)
	{
		// initialize near[i] to infinity
		near[i] = I;
		for (j = i; j <= n; j++)
		{
			// Find the minimum cost edge
			if (Cost[i][j] < min)
			{
				// Set the new min value
				min = Cost[i][j];
				u = i;
				v = j;
			}
		}
	}

	t[0][0] = u;
	t[1][0] = v;
	// If the node has been selected,
	// update the near to reflect that
	near[u] = near[v] = 0;

	// Initialize the Near Array
	for (i = 1; i <= n; i++)
	{
		if (near[i] != 0)
		{
			// Check all of the vertices to check if they are
			// nearer to u or nearer to v
			if (Cost[i][u] < Cost[i][v])
				near[i] = u;
			else
				near[i] = v;

		}
	}

	// Repeat the process
	for (i = 1; i < n - 1; i++)
	{
		min = I;
		for (j = 1; j <= n; j++)
		{
			// Find the minimum edge and don't recheck an edge
			// that was already selected
			if (near[j] != 0 && Cost[j][near[j]] < min)
			{
				k = j;
				min = Cost[j][near[j]];
			}
		}
		t[0][i] = k;
		t[1][i] = near[k];

		// include this vertex so we do not use it again in the check
		near[k] = 0;

		for (j = 1; j <= n; j++)
		{
			// If the value is not include and is nearer to k, 
			if (near[j] != 0 && Cost[j][k] < Cost[j][near[j]])
				near[j] = k;
		}
	}

	// Print the solution
	PrintMST(t, Cost);
}


/*
	Kruskal's Program
*/

// union/join
void join(int u, int v, int Set[N])
{
	if (Set[u] < Set[v])
	{
		Set[u] += Set[v];
		Set[v] = u;
	}
	else
	{
		Set[v] += Set[u];
		Set[u] = v;
	}
}

// Collapsing find
int find(int u, int Set[N])
{
	int x = u, v = 0;

	while (Set[x] > 0)
	{
		x = Set[x];
	}

	while (u != x)
	{
		v = Set[u];
		Set[u] = x;
		u = v;
	}

	return x;
}

void Kruskals(int Edges[3][N + 1], int n)
{
	int Set[N] = { -1, -1, -1, -1, -1, -1, -1, -1 };
	int Included[9] = { 0 };
	int t[2][N-2];

	int i = 0, j, k, u, v, min = I, e = 9;

	// N - 1 edges
	while (i < n - 1)
	{
		// Reset min back to infinity
		min = I;
		// Find the minimum cost edge
		for (j = 0; j < e; j++)
		{
			// Only if the value of included[j] is zero can we consider it.
			// If not, the edge has already been searched and included
			if (Included[j] == 0 && Edges[2][j] < min)
			{
				min = Edges[2][j];
				u = Edges[0][j];
				v = Edges[1][j];
				// record j in k so we can include it
				k = j;
			}
		}

		// If these are not equal, we will include in the solution.
		// If they are equal that means they form a cycle and should be skipped
		if (find(u, Set) != find(v, Set))
		{
			t[0][i] = u;
			t[1][i] = v;
			// Perform a union because we have found the lowest cost edge
			join(find(u, Set), find(v, Set), Set);
			// Move to the next edge
			i++;
		}
		// Include the edge
		Included[k] = 1;
	}

	PrintMST(t, Edges);
}