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
	void Create(int* A, int n, struct Node*& head, bool circular = true)
	{
		struct Node* t, * last;
		int i;

		head = (struct Node*)malloc(sizeof(struct Node));
		head->data = A[0];

		if (!circular)
			head->prev = head->next = NULL;
		else
			head->prev = head->next = head;

		last = head;

		for (i = 1; i < n; i++)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = A[i];
			
			if (!circular)
			{
				t->next = last->next;
				t->prev = last;
				last->next = t;
				last = t;
			}
			else
			{
				t->next = head;
				head->prev = t;
				t->prev = last;
				last->next = t;
				last->prev = t;
				last = t;
			}
		}
	}

	void Display(struct Node* p, bool circular = true)
	{
		struct Node* temp = p;
		if (!p)
			return;

		if (!circular)
		{
			while (temp != NULL)
			{
				printf("%d ", temp->data);
				temp = temp->next;
			}
		}
		else
		{
			do
			{
				printf("%d ", temp->data);
				temp = temp->next;
			} while (temp != p);
		}
		// Create a new line after list
		printf("\n");
	}

	int Length(struct Node* p, bool circular = true)
	{
		if (!p)
			return 0;

		struct Node* temp = p;
		int len = 0;

		if (!circular)
		{
			while (temp)
			{
				len++;
				temp = temp->next;
			}
		}
		else
		{
			do
			{
				len++;
				temp = temp->next;
			} while (temp != p);
		}
		
		return len;
	}

	int Insert(int x, int index, struct Node*& head, bool circular = true)
	{
		// Get the length to use throughout the function
		int len = Length(head);
		// Check to see if the index is valid
		if (index < 0 || index > len)
			return -1;
		
		// Create a new node to be inserted
		struct Node* t;
		t = (struct Node*)malloc(sizeof(Node));

		// Set the data to the desired inserted data
		t->data = x;

		// If head is an empty list, set head to t
		if (!head)
		{
			if (circular)
			{
				head = t;
				head->next = head;
				head->prev = head;
			}
			else
			{
				head = t;
				head->next = NULL;
				head->prev = NULL;
			}

			return 0;
		}

		// Insert at the front of the list
		if (index == 0)
		{
			if (!circular)
			{
				t->next = head;
				t->prev = NULL;
				head->prev = t;
				head = t;
			}
			else
			{
				t->next = head;
				t->prev = head->prev;
				head->prev->next = t;
				head->prev = t;
				head = t;		
			}
		}
		else if (index == len)
		{
			t->next = head;
			t->prev = head->prev;
			head->prev->next = t;
			head->prev = t;
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

	int Delete(int index, struct Node*& head, bool circular = true)
	{
		// Get the length to use throughout the function
		int len = Length(head);

		// Check to see if the index is valid
		if (index < 0 || index > len)
			return -1;

		// Create a temp node*
		struct Node* p = head;
		
		// Delete the first Node
		if (index == 0)
		{
			if (len == 1)
			{
				head->next = NULL;
				head->prev = NULL;
				
				free(head);
				head = NULL;
				
				return 0;
			}

			if (!circular)
			{
				head = head->next;

				// if head is not NULL
				if (head)
					head->prev = NULL;

				free(p);
			}
			else
			{
				if (p)
				{
					p->prev->next = p->next;
					p->next->prev = p->prev;

					head = head->next;
					
					free(p);
				}
			}
		}
		else if (index == len)
		{
			int i = 1;
			for (; i < index - 1; i++)
				p = p->next;

			p->next = head;

			free(head->prev);

			head->prev = p;

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
		// Check to see if the list is empty
		struct Node* temp = head, *current = head->next, *p = head;
		
		do
		{
			temp = current->next;

			current->next = p;
			p->prev = current;
			head->next = current;
			current->prev = head;

			p = current;
			current = temp;

		} while (temp != head);

		head = p;
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
			trailing = leading->prev;
			while (leading != trailing)
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
				head->prev = head;
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
		struct Node* temp = p;
		do
		{
			if (temp->data <= temp->next->data)
			{
				printf("temp: %d, temp->next: %d \n", temp->data, temp->next->data);
				temp = temp->next;
			}
				
			else
				return 0;
		} while (temp->next != p);

		return 1;
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

	/*
		This function uses two temp pointers p,q.
		It moves q over two times per loop and p only once;
		Once q == null, p will be at the middle number or 
		half way through the list
	*/

	int FindMiddleNumber(struct Node* head)
	{
		// Declare two temp pointers
		struct Node* p, *q;

		// Set both pointers to the head of the list
		p = q = head;

		// While q is not null
		while (q)
		{
			// Move q to the next node
			q = q->next;

			// Check to see if q is not null, move q to the next node
			if (q) q = q->next;

			// Check to see if q is not null, move p to the next node
			if (q) p = p->next;
		}

		// return the data at the middle node
		return p->data;
	}
};

