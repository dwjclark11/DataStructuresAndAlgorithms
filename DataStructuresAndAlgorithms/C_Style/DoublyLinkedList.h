#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* prev;
	struct Node* next;
	int data;
}; 


struct DoublyLinkedList
{
	void Create(int* A, int n, struct Node*& head)
	{
		struct Node* t, * last;
		int i;

		head = (struct Node*)malloc(sizeof(struct Node));
		head->data = A[0];
		head->prev = head->next = NULL;

		last = head;

		for (i = 1; i < n; i++)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = A[i];
			t->next = last->next;
			t->prev = last;
			last->next = t;
			last = t;
		}
	}

	void Display(struct Node* p)
	{
		struct Node* temp = p;

		while (temp)
		{
			printf("%d ", temp->data);
			temp = temp->next;

		}
		printf("\n");
	}

	int Length(struct Node* p)
	{
		struct Node* temp = p;
		int len = 0;
		while (temp)
		{
			len++;
			temp = temp->next;

		}

		return len;
	}

	int Insert(int x, int index, struct Node*& head)
	{
		// Check to see if the index is valid
		if (index < 0 || index > Length(head))
			return -1;

		// Create a new node to be inserted
		struct Node* t;
		t = (struct Node*)malloc(sizeof(Node));

		// Set the data to the desired inserted data
		t->data = x;

		// Insert at the front of the list
		if (index == 0)
		{
			t->next = head;
			t->prev = NULL;

			head->prev = t;
			head = t;
		}
		else // Insert at a given index
		{
			int i = 0;
			struct Node* p = head;
			
			for (; i < index - 1; i++)
				p = p->next;

			t->next = p->next;
			t->prev = p;

			// See if p->next is NULL
			if (p->next)
				p->next->prev = t;

			p->next = t;
		}

		return 0;
	}

	int Delete(int index, struct Node*& head)
	{
		// Check to see if the index is valid
		if (index < 0 || index > Length(head))
			return -1;

		// Create a temp node*
		struct Node* p = head;
		
		// Delete the first Node
		if (index == 0)
		{
			head = head->next;
			
			// if head is not NULL
			if (head)
				head->prev = NULL;

			free(p);
		}
		else // Delete at a given index
		{
			int i = 0;
			for (; i < index - 1; i++)
				p = p->next;

			p->prev->next = p->next;

			if(p->next)
				p->next->prev = p->prev;

			free(p);
		}
		
		// Return zero if successful
		return 0;
	}

	void Reverse(struct Node*& head)
	{
		struct Node* temp, *p = head;

		while (p)
		{
			temp = p->next;
			p->next = p->prev;
			p->prev = temp;
			p = p->prev;

			// Ensure that p is not NULL
			if (p != NULL && p->next == NULL)
				head = p;
		}
	}

	void Sort(struct Node*& p, bool descending = false)
	{
		int swapped;
		struct Node* leading;
		struct Node* trailing = NULL;

		// Check to see if the list is empty
		if (!p)
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

		// Sort the inserted list
		Sort(p);

		// Declare the new and trailing pointers
		struct Node* newNode, * trailing = NULL;

		// Allocate the new node to heap
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;

		// If there are no other nodes in the list, assign the first node to the new Node
		if (!head)
			head = newNode;
		else
		{
			// Search the lust to find the correct position
			while (p && p->data < x)
			{
				trailing = p;
				p = p->next;
			}

			if (p == head)
			{
				newNode->next = head;
				head = newNode;
				head->prev = NULL;
			}
			else
			{
				newNode->next = trailing->next;
				newNode->prev = trailing;
				trailing->next = newNode;
			}
		}
	}

	int IsSorted(struct Node* p)
	{
		while (p->next)
		{
			if (p->data < p->next->data)
				p = p->next;
			else
				return -1;
		}

		return 0;
	}

	void RemoveDuplicates(struct Node* p)
	{
		struct Node* q = p->next;
		struct Node* t = p->prev;

		while (q)
		{
			// If the data is not the same, move to the next node
			if (p->data != q->data)
			{
				t = p;
				p = p->next;
				p->prev = t;
				q = q->next;
			}
			else
			{
				t = p;
				p->next = q->next;
				p->prev = t;

				free(q);
				q = p->next;
			}
		}
	}
};

