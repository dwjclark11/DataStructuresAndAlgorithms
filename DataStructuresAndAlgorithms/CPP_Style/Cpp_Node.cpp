#include "Cpp_Node.h"
#include <iostream>

LinkedList::LinkedList(int A[], int n)
{
	Node* last = nullptr, *t;
	
	head = new Node;
	head->data = A[0];
	head->next = nullptr;
	last = head;
	// i is equal to 1 because we already set the first node to the first element in the array
	for (int i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = nullptr;
		last->next = t;
		last = t;
	}
}

LinkedList::~LinkedList()
{
	Node* p = head;

	while (head)
	{
		head = head->next;
		delete p;
		p = head;
	}
}

void LinkedList::Display()
{
	Node* p = head;

	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

int LinkedList::Insert(int index, int x)
{
	// Create a helper pointer for traversing the linked list
	Node* p = head;
	
	// Check to see if the index is valid
	if (index < 0 || index > Length())
		return -1;

	// Create a new node to insert
	Node* t = nullptr;
	t = new Node;
	t->data = x;

	// If the index is 0, insert at the front
	if (index == 0)
	{
		t->next = head;
		head = t;
	}
	else
	{
		// Move the pointer to the desired position
		for (int i = 0; i < index - 1; i++)
			p = p->next;

		// Insert the node in the correct position a change the links
		t->next = p->next;
		p->next = t;
	}

	return 0;
}

int LinkedList::Delete(int index)
{
	// Create 2 helper pointers 
	struct Node* p = head;
	struct Node* q = nullptr;

	// Create a variable to return the deleted value
	int x = -1;

	// Check to see if the index is valid
	if (index < 1 || index > Length())
		return -1;

	// Check to see if the first node is to be deleted
	if (index == 1)
	{
		// Set p pointer to equal head location
		p = head;
		// Set the return data to head->data
		x = head->data;
		// Set head to the next node
		head = head->next;
		
		// Deallocate the node at p
		delete p;

		return x;
	}
	else
	{
		// Traverse the linked list to get to the desired position
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		// Set trail->next to p->next so we link the trail with the next element in the linked list
		q->next = p->next;
		// Take the value of p and assign it to x for the return value
		x = p->data;
		// Deallocate p from the heap
		delete p;
		// Retrun the deleted value
		return x;
	}
}

int LinkedList::Length()
{
	Node* p = head;
	int length = 0;

	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}

void LinkedList::Sort()
{

}
