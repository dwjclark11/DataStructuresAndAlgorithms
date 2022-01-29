#pragma once
#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;

} *first; // Becomes a global pointer

struct C_LinkedList
{
	// Create the linked list
	void Create(int A[], int n)
	{
		int i; // Used for scanning the array
		struct Node* t, * last;
		// Allocate a new node 
		first = (struct Node*)malloc(sizeof(struct Node));
		// Assign the data to the first element of the array
		first->data = A[0];
		// Set the next node to Null
		first->next = NULL;
		// Set the last Node to equal the first node
		last = first;

		// Loop through all the elements to assign the links 
		for (i = 1; i < n; i++)
		{
			// A new node must be created for each element
			t = (struct Node*)malloc(sizeof(struct Node));
			// Set the data to the next element in the array
			t->data = A[i];
			// Set the next node to NULL
			t->next = NULL;
			// Have the last next node = to the address of t
			last->next = t;
			// Set the address of the last node to t
			last = t;
		}

	}

	void Display(struct Node* p)
	{
		while (p != NULL)
		{
			// Print the data
			printf("data: %d, Node Address: %d\n", p->data, p->next);
			// Move to the next node
			p = p->next;
		}
	}

	// Recursive Display --> If you want to print in reverse set value to true
	void RDisplay(struct Node* p, bool reverse = false)
	{
		if (p != NULL)
		{
			if (!reverse)
			{
				printf("data: %d, Node Address: %d\n", p->data, p->next);
				RDisplay(p->next, reverse);
			}
			else
			{
				RDisplay(p->next, reverse);
				printf("data: %d, Node Address: %d\n", p->data, p->next);
			}
			
		}
	}

	int Count(struct Node* p)
	{
		int count = 0;
		while (p != NULL)
		{
			count++;
			p = p->next;
		}

		return count;
	}

	// Count Recursively
	int RCount(struct Node* p)
	{
		// Base Case
		if (p == 0)
			return 0;
		else
			return RCount(p->next) + 1;
	}

	int SumOfNodes(struct Node* p)
	{
		int sum = 0;
		while (p != NULL)
		{
			sum += p->data;
			p = p->next;
		}
		return sum;
	}

	// Sum Recursive
	int RSumOfNodes(struct Node* p)
	{
		// Base Case
		if (p == NULL)
			return 0;
		else
			return RSumOfNodes(p->next) + p->data;	
	}

	int Max(struct Node* p)
	{
		int max = INT_MIN;
		while (p != NULL)
		{
			if (p->data > max)
				max = p->data;

			p = p->next;
		}
		return max;
	}

	// Max Recursive
	int RMax(struct Node* p)
	{
		int x = 0;
		// Base Case
		if (p == NULL)
			return INT_MIN;
		// Set the x value to the next link traversal
		x = RMax(p->next);

		// Use the ternary operator to return either x or p-data
		return x > p->data ? x : p->data;
	}

	int Min(struct Node* p)
	{
		int min = INT_MAX;
		while (p != NULL)
		{
			if (p->data < min)
				min = p->data;

			p = p->next;
		}
		return min;
	}

	int RMin(struct Node* p)
	{
		int x = 0;
		// Base Case
		if (p == NULL)
			return INT_MAX;

		// Set the x value to the next link traversal
		x = RMin(p->next);
		
		return x < p->data ? x : p->data;
	}

	struct Node* LSearch(struct Node* p, int key)
	{
		while (p != NULL)
		{
			if (key == p->data)
				return p;

			p = p->next;
		}
		return NULL;
	}

	struct Node* RSearch(struct Node* p, int key)
	{
		// Base Case 
		if (p == NULL)
			return NULL;

		if (key == p->data)
			return p;

		return RSearch(p->next, key);
	}

	// This is an improved linear Search -->Move to front
	struct Node* Search(struct Node* p, int key)
	{
		struct Node* q = NULL;

		while (p != NULL)
		{
			
			if (key == p->data)
			{
				if (p != first)
				{
					q->next = p->next;
					p->next = first;
					first = p;
					return p;
				}
				else
				{
					return first;
				}
			}

			q = p;
			p = p->next;
		}
		return NULL;
	}
};
