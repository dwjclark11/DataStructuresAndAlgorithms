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

	// Recursive Display
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
};
