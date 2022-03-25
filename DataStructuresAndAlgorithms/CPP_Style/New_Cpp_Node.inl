#include "Cpp_Node.h"
#include <iostream>

template <typename T>
void LinkedList<T>::Swap1(T a, T b)
{
	Node<T>* prevNode1 = nullptr, * prevNode2 = nullptr, * node1 = head, * node2 = head, * temp = nullptr;

	// Check if the list is empty
	if (!head)
		return;

	// If 'a' and 'b' are the same value, leave the nodes
	if (a == b)
		return;

	// Search for node1
	while (node1 && node1->data != a)
	{
		prevNode1 = node1;
		node1 = node1->next;
	}
	// Search for node2
	while (node2 && node2->data != b)
	{
		prevNode2 = node2;
		node2 = node2->next;
	}

	if (node1 && node2)
	{
		if (prevNode1)
			prevNode1->next = node2;
		else
			head = node2;

		if (prevNode2)
			prevNode2->next = node1;
		else
			head = node1;

		// Swap the nodes
		temp = node1->next;
		node1->next = node2->next;
		node2->next = temp;
	}
	else
		std::cout << "Unable to swap!" << std::endl;
}
template <typename T>
Node<T>* LinkedList<T>::Swap(Node<T>* a, Node<T>* b)
{
	Node<T>* temp = b->next;
	b->next = a;
	a->next = temp;
	return b;
}

template <typename T>
void LinkedList<T>::RReverseLinks(Node<T>* head, Node<T>** headPtr)
{
	Node<T>* first;
	Node<T>* second;

	// If the list is empty, no need to reverse
	if (!head)
		return;

	first = head;
	second = first->next;

	if (!second)
	{
		*headPtr = first;
		return;
	}

	RReverseLinks(second, headPtr);

	second->next = first;
	first->next = nullptr;
}
template <typename T>
LinkedList<T>::LinkedList(T A[], int n)
{
	Node<T>* last = nullptr, * t;

	head = new Node<T>;
	head->data = A[0];
	head->next = nullptr;
	last = head;
	// i is equal to 1 because we already set the first node to the first element in the array
	for (int i = 1; i < n; i++)
	{
		t = new Node<T>;
		t->data = A[i];
		t->next = nullptr;
		last->next = t;
		last = t;
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* p = head;
	Node<T>* next;
	while (p)
	{
		next = p->next;
		delete p;
		p = next;
	}
}

template <typename T>
void LinkedList<T>::Display()
{
	Node<T>* p = head;

	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
template <typename T>
T LinkedList<T>::Insert(int index, T x)
{
	// Create a helper pointer for traversing the linked list
	Node<T>* p = head;

	// Check to see if the index is valid
	if (index < 0 || index > Length())
		return -1;

	// Create a new node to insert
	Node<T>* t = nullptr;
	t = new Node<T>;
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

template <typename T>
T LinkedList<T>::Delete(int index)
{
	// Create 2 helper pointers 
	struct Node<T>* p = head;
	struct Node<T>* q = nullptr;

	// Create a variable to return the deleted value
	T x = -1;

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

template <typename T>
int LinkedList<T>::Length()
{
	Node<T>* p = head;
	int length = 0;

	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}
template <typename T>
void LinkedList<T>::Sort()
{
	Node<T>** headPtr;
	int swap = 0;
	// Get the length/Count of the linked-list
	int count = Length();

	for (int i = 0; i < count; i++)
	{
		headPtr = &head;
		swap = 0;

		for (int j = 0; j < count - i; j++)
		{
			// Create 2 new Node ptrs for comparing and swaping nodes
			Node<T>* p1 = *headPtr;
			Node<T>* p2 = p1->next;

			// Check that p2 is not nullptr and break if so, no need to try to check nullptr
			if (!p2) break;

			if (p1->data > p2->data)
			{
				*headPtr = Swap(p1, p2);
				swap = 1;
			}

			headPtr = &(*headPtr)->next;
		}

		if (!swap)
			break;
	}
}

template <typename T>
bool LinkedList<T>::IsSorted()
{
	Node<T>* temp = head;
	while (temp->next)
	{
		if (temp->data <= temp->next->data)
			temp = temp->next;
		else
			return false;
	}
	return true;
}
template <typename T>
void LinkedList<T>::RemoveDuplicates()
{
	Node<T>* p = head;
	Node<T>* q = p->next;

	while (q)
	{
		// If the data is not the same, move to the next node
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}

template <typename T>
void LinkedList<T>::ReverseData()
{
	int index = 0;
	Node<T>* q = head;

	// Create an array to hold all the data
	int* A = new int[sizeof(int) * Length()];

	// Fill the array with all the data from the list
	while (q)
	{
		A[index] = q->data;
		q = q->next;
		index++;
	}

	// Set q back to the first node in the list
	q = head;
	index--;

	// Copy all the data from the array into the list in reverse order
	while (q)
	{
		q->data = A[index];
		q = q->next;
		index--;
	}
}
template <typename T>
void LinkedList<T>::ReverseLinks()
{
	/*
		This uses sliding pointers
	*/
	Node<T>* p = head;		// Leading Node
	Node<T>* q = nullptr;	// Modified Node
	Node<T>* r = nullptr;	// Previous Node

	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		// We need to keep track of r so set the q->next node to r
		q->next = r;
	}

	// Set the head node to the modified node;
	head = q;
}

template <typename T>
void LinkedList<T>::Reverse()
{
	RReverseLinks(head, &head);
}

// Creates a new list with by concatinating the two, the calling list and the input list
template <typename T>
Node<T>* LinkedList<T>::Concat(Node<T>** second)
{
	Node<T>* first = head;
	Node<T>* third = head;

	while (first->next)
		first = first->next;

	first->next = *second;

	// Set the old lists to nullptr
	*second = nullptr;
	head = nullptr;

	return third;
}
template <typename T>
Node<T>* LinkedList<T>::Merge(LinkedList<T>& list2)
{
	// Check to see if the calling list is sorted
	if (!IsSorted())
		Sort();
	// Check to see if the second list is sorted
	if (!list2.IsSorted())
		list2.Sort();

	Node<T>* first = head;
	Node<T>* second = *list2.GetHead();
	Node<T>* last;
	Node<T>* third;

	if (first->data < second->data)
	{
		third = last = first;
		first = first->next;
		third->next = nullptr;
	}
	else
	{
		third = last = second;
		second = second->next;
		third->next = nullptr;

	}
	while (first && second)
	{
		if (first->data < second->data)
		{
			last->next = first;
			last = first;
			first = first->next;
			last->next = nullptr;
		}
		else
		{
			last->next = second;
			last = second;
			second = second->next;
			last->next = nullptr;

		}
	}

	// link the remaing list
	if (first) last->next = first;
	if (second) last->next = second;

	// Set the ptrs to nullptr
	head = nullptr;
	*list2.GetHead() = nullptr;

	return third;
}

template <typename T>
bool LinkedList<T>::IsLooped()
{
	Node<T>* p, * q;
	p = q = head;

	while (p && q)
	{
		p = p->next;
		q = q->next;
		// Check to see if q is nullptr, move q to next node if not nullptr
		q = q ? q->next : q;

		if (p == q)
			return true;
	}
	return false;
}

