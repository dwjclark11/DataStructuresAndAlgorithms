#pragma once
#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;

};

struct C_LinkedList
{
	// Create the linked list
	void Create(int A[], int n, struct Node*& head)
	{
		int i; // Used for scanning the array
		struct Node* t, * last;
		// Allocate a new node 
		head = (struct Node*)malloc(sizeof(struct Node));
		// Assign the data to the first element of the array
		head->data = A[0];
		// Set the next node to Null
		head->next = NULL;
		// Set the last Node to equal the first node
		last = head;

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
			printf(" %d, ", p->data);
			// Move to the next node
			p = p->next;
		}
		printf("\n");
	}

	// Recursive Display --> If you want to print in reverse set value to true
	void RDisplay(struct Node* p, bool reverse = false)
	{
		if (p != NULL)
		{
			if (!reverse)
			{
				printf("data: %d, Node Address: %p\n", p->data, p->next);
				RDisplay(p->next, reverse);
			}
			else
			{
				RDisplay(p->next, reverse);
				printf("data: %d, Node Address: %p\n", p->data, p->next);
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
	struct Node* Search(struct Node* p, int key, struct Node& head)
	{
		struct Node* q = NULL;

		while (p != NULL)
		{
			
			if (key == p->data)
			{
				if (p != &head)
				{
					q->next = p->next;
					p->next = &head;
					head = *p;
					return p;
				}
				else
				{
					return &head;
				}
			}

			q = p;
			p = p->next;
		}
		return NULL;
	}

	int Insert(/*struct Node* p, */struct Node*& head, int index, int x)
	{
		struct Node* p = head;
		int i = 0;
		// Check to see if the index is valid
		if (index < 0 || index > Count(p))
			return -1;

		// Create a new node to insert
		struct Node* t = NULL;
		t = (struct Node*)malloc(sizeof(Node));
		t->data = x;

		// If index is 0, insert at the front of the linked list
		if (index == 0)
		{
			t->next = head;
			head = t;
		}
		else
		{
			// Move the pointer to the desired position for insertion
			for (; i < index - 1; i++)
				p = p->next;

			// Insert the Node in the correct position and change the links accordingly
			t->next = p->next;
			p->next = t;
		}

		return 0;
	}

	// Bubble Sort 
	void Sort(struct Node*& p, bool descending = false)
	{
		int swapped;
		struct Node* leading;
		struct Node* trailing = NULL;
		
		// Check to see if the list is empty
		if (p == NULL)
			return;

		do
		{
			swapped = 0;
			leading = p;

			while (leading->next != trailing)
			{
				if (!descending)
				{
					if (leading->data > leading->next->data)
					{
						// Swap the data 
						int temp = leading->data;
						leading->data = leading->next->data;
						leading->next->data = temp;
						swapped = 1;
					}
				}
				else
				{
					if (leading->data < leading->next->data)
					{
						// Swap the data 
						int temp = leading->data;
						leading->data = leading->next->data;
						leading->next->data = temp;
						swapped = 1;
					}
				}
				// Move the leading ptr to the next node
			
				leading = leading->next;
			}
			trailing = leading;
		} while (swapped);
	}

	void SortedInsert(struct Node*& head, int x)
	{
		struct Node* p = head;
		// Sort the list
		Sort(p);

		// declare new and trailing pointers
		struct Node* newNode, * trailing = NULL;

		// Allocate new node to heap
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = NULL;

		// If there are no other nodes in the list, assign the first node to the newNode
		if (head == NULL)
			head = newNode;
		else
		{
			// Search the list to find the correct position
			while (p && p->data < x)
			{
				trailing = p;
				p = p->next;
			}

			if (p == head)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				newNode->next = trailing->next;
				trailing->next = newNode;
			}
		}
	}

	int Delete(struct Node*& head, int index)
	{
		struct Node* p = head;
		// Declare Variables
		struct Node* trail = NULL;
		int x = -1, i;

		if (index < 1 || index > Count(p))
			return -1;
		
		// If the first node is to be deleted
		if (index == 1)
		{
			trail = head;
			x = head->data;
			head = head->next;
			free(trail);

			// Return the deleted element
			return x;
		}
		else // Not the first element
		{
			// Traverse through the linked list to the desired position
			for (i = 0; i < index - 1; i++)
			{
				// Set the trail to p and move p to the next node
				trail = p;
				p = p->next;
			}
			// Set trail->next to p->next so we link the trail with the next element in the linked list
			trail->next = p->next;
			// Take the value of p and assign it to x for the return value
			x = p->data;
			// Deallocate p from the heap
			free(p);
			// Retrun the deleted value
			return x;
		}
	}

	int IsSorted(struct Node* p)
	{
		while (p->next != NULL)
		{
			if (p->data < p->next->data)
				p = p->next;
			else
				return false;
		}
		return true;
	}

	void RemoveDuplicates(struct Node*& p)
	{
		struct Node* q = p->next;

		while (q != NULL)
		{
			// If data is not the same, move to the next node, P is tail node, Q is leading
			if (p->data != q->data)
			{
				p = q;
				q = q->next;
			}
			else
			{
				p->next = q->next;
				free(q);
				q = p->next;
			}
		}
	}

	/* Reversing Linked-Lists */
	void ReverseData(struct Node*& p)
	{
		/*
			This reversal uses an array that will copy the data from the linked-list
			then reverse copy the data back into the linked-list's data portion
		*/
		
		// Use a new pointer and index to help traverse the linked-list
		int index = 0;
		struct Node* q = p;
		// Create a pointer to an integer --> This will help create the needed array
		int* A;
		// Allocate size based on the number/Count of nodes in the linked-list
		A = (int*)malloc(sizeof(int) * Count(p));

		// Traverse the linked-list and copy the data of each node into the array
		while (q != NULL)
		{
			A[index] = q->data;
			q = q->next;
			index++;
		}
		// Send q back to the front to traverse again for the reverse copy
		q = p;
		index--;

		// Copy the data from the array back into the list
		while (q != NULL)
		{
			q->data = A[index];
			q = q->next;
			index--;
		}
	}
	
	void ReverseLinks(struct Node*& head)
	{
		struct Node* p = head;
		/*
			This function will reverse the linked list using sliding pointers; This is preferred over reversing 
			the data because it only takes the space of the pointers rather than a copy of the actual data! Say that
			the data you are moving is a Record rather than an int. You would be copying all the data of the Record rather
			than just a pointer/link to that record. More space required, less efficient.

				- 3 Pointers are needed so we do not lose track of the nodes when changing the links
				- The pointers are as follows: 
					- r --> Previous Node
					- q --> Modified Node
					- p --> Leading Node

					Slide the pointers like this: r = q = p = p->next;
		*/

		struct Node* q = NULL, *r = NULL;

		while (p != NULL)
		{
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}
		
		// First is the Global Head of the linked list!
		head = q;
	}
	// Recursive reversal of the links
	void RReverseLinks(struct Node* head, struct Node** fhead)
	{
		struct Node* first;
		struct Node* rest;

		if (head == NULL)
			return;
		
		first = head;
		rest = first->next;
		
		if (rest == NULL)
		{
			*fhead = first;
			return;
		}

		RReverseLinks(rest, fhead);

		rest->next = first;
		first->next = NULL;
	}

	// Wrapper for the Recursive Reverse
	void reverse(struct Node** head)
	{
		RReverseLinks(*head, head);
	}

	void DeleteList(struct Node** head)
	{
		struct Node* current = *head;
		struct Node* next;

		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*head = NULL;
	}
	struct Node* Concat(struct Node*& first, struct Node*& second)
	{
		struct Node* third = first;

		// Scroll to the end of the list
		while (first->next != NULL)
			first = first->next;

		first->next = second;
		
		second = NULL;
		first = NULL;

		return third;
	}

	/*
		This merge Function Takes two pointer References of Nodes and returns a
		new merged and sorted linked-list. It also removes the old pointers
		so there is now only one list!
	*/

	struct Node* Merge(struct Node*& first, struct Node*& second)
	{
		// Check to see if lists are sorted, if not Sort them
		if (!IsSorted(first))
			Sort(first); 
		
		if (!IsSorted(second))
			Sort(second);

		// Make two temporary pointers to lists
		struct Node* last;
		struct Node* third;

		if (first->data < second->data)
		{
			third = last = first;
			first = first->next;
			third->next = NULL;
		}
		else
		{
			third = last = second;
			second = second->next;
			third->next = NULL;
		}

		while (first && second)
		{
			if (first->data < second->data)
			{
				last->next = first;
				last = first;
				first = first->next;
				last->next = NULL;
			}
			else
			{
				last->next = second;
				last = second;
				second = second->next;
				last->next = NULL;
			}
		}

		// Link the remaining links if list is not null
		if (first) last->next = first;
		if (second) last->next = second;

		// Remove the pointers to the list
		first = NULL;
		second = NULL;

		// Return the new merged list
		return third;
	}

	int CheckForLoop(struct Node* head)
	{
		struct Node* p, * q;
		p = q = head;

		while (p && q)
		{
			p = p->next;
			q = q->next;

			q = q ? q->next : q;

			if (p == q)
				return 1;
		}
		return 0;
		//do
		//{
		//	p = p->next;
		//	q = q->next;
		//	q = q ? q->next : q;
		//} while (p && q && p != q);

		//if (p == q)
		//	return 1;
		//else
		//	return 0;
	}
};

struct Circ_LinkedList
{
	void Create(int* A, int n, struct Node*& head)
	{
		int i;
		struct Node* t, *last;

		head = (struct Node*)malloc(sizeof(struct Node));
		head->data = A[0];

		// Point next to head making it circular
		head->next = head;
		last = head;

		for (i = 1; i < n; i++)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = A[i];
			t->next = last->next;
			last->next = t;
			last = t;
		}
	}

	void Display(struct Node* head)
	{
		// Create a temporary node that points to head
		struct Node* p = head;
		do
		{
			printf("%d ", p->data);
			
			p = p->next;

		} while (p != head);
		printf("\n");
	}

	int Length(struct Node* p)
	{
		struct Node* temp = p;
		int len = 0;

		do
		{
			len++;
			temp = temp->next;

		} while (temp->next != p);

		return len;
	}

	void Insert(int index, int x, struct Node* head)
	{
		struct Node* t, * p = head;
		int i;
		
		// Check to see if the index is within the proper range
		if (index < 0 || index > Length(head))
		{
			printf("Cannot insert at %d, because it is beyond the count of the list %d", index, Length(head));
			return;
		}
		
		// Insert at the head of the list
		if (index == 0)
		{
			// Create Set the new node
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			// Check to see if head is null and point to self
			if (head == NULL)
			{
				head = t;
				head->next = head;
			}
			else
			{
				while (p->next != head)
					p = p->next;

				p->next = t;
				t->next = head;
				head = t;
			}
		}
		else // Insert at the given index
		{
			for (i = 0; i < index - 1; i++)
				p = p->next;

			t = (struct Node*)malloc(sizeof(Node));
			t->data = x;
			t->next = p->next;
			p->next = t;
		}
	}

	int Delete(struct Node** head, int index)
	{
		int i, x = 0;
		// Check to see if the list is empty
		if (*head == NULL)
			return -1;

		// Check to see if there is only one node
		if ((*head)->next == *head)
		{
			x = (*head)->data;
			free(*head);
			*head = NULL;
			return x;
		}

		struct Node* p = *head, * q;

		// Check to see if the head has to be deleted
		if (index == 1)
		{
			// Find the last node in the list
			while (p->next != *head)
				p = p->next;

			p->next = (*head)->next;
			
			x = (*head)->data;
			free(*head);
			*head = p->next;

		}
		else
		{
			for (i = 0; i < index - 2; i++)
				p = p->next;

			q = p->next;
			p->next = q->next;
			x = q->data;
			free(q);
		}
		return x;
	}
};