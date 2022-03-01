#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
	: head(nullptr)
{

}

DoublyLinkedList::DoublyLinkedList(int* A, int n)
	: head(nullptr)
{
	Node* last = nullptr, *t;
	head = new Node;
	head->data = A[0];
	head->next = head;
	head->prev = head;

	last = head;

	for (int i = 1; i < n; i++)
	{
		t = new Node();
		t->data = A[i];
		t->prev = last;
		t->next = head;
		last->next = t;
		last = t;
	}
	head->prev = last;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if (head)
	{
		while (head->next != head)
		{
			Node* temp = head->next;
			temp->next->prev = head;
			head->next = temp->next;
			delete temp;
			//std::cout << "Deleting Node!\n";
		}
		//std::cout << "Deleting Head!\n";
		delete head;
	}
}

void DoublyLinkedList::Display()
{
	// Check to see if head is nullptr
	if (!head)
		return;

	Node* p = head;
	do
	{
		std::cout << p->data << " ";
		p = p->next;
	} while (p != head);
	std::cout << std::endl;
}

void DoublyLinkedList::InsertFront(int value)
{
	if (!head)
	{
		head = new Node;
		head->data = value;
		head->next = head;
		head->prev = head;
	}
	else
	{
		Node* t = new Node;
		t->data = value;
		t->next = head;
		t->prev = head->prev;
		head->prev->next = t;
		head->prev = t;
		head = t;
	}
}

void DoublyLinkedList::Insert(int value, int index)
{
	// Get Length
	int len = Length();
	
	if (index < 0 || index > len)
		return;

	if (index == 0)
		InsertFront(value);
	else if (index == len)
		InsertBack(value);
	else
	{
		Node* t = new Node;
		Node* p = head;
		t->data = value;

		// Move pointer to the previous index 
		for (int i = 0; i < index - 1; i++)
			p = p->next;

		t->next = p->next;
		t->prev = p;
		p->next->prev = t;
		p->next = t;
	}
}

void DoublyLinkedList::InsertBack(int value)
{

	if (!head)
	{
		head = new Node;
		head->data = value;
		head->next = head;
		head->prev = head;
	}
	else
	{
		Node* t = new Node;
		t->data = value;

		t->prev = head->prev;
		t->next = head;
		head->prev->next = t;
		head->prev = t;
	}
}

void DoublyLinkedList::DeleteFront()
{
	// If the list is empty, nothing to delete
	if (!head)
		return;

	Node* temp = head;
	head = head->next;
	head->prev = temp->prev;
	temp->prev->next = head;

	
	delete temp;

}

void DoublyLinkedList::DeleteBack()
{
	// Check to see if list is empty
	if (!head)
		return;

	if (Length() > 1)
	{
		Node* p = head->prev;
		head->prev->prev->next = head;
		head->prev = head->prev->prev;

		delete p;
	}
	else
	{
		delete head;
		head = nullptr;
	}


}

int DoublyLinkedList::Length()
{
	// If the list is empty leave
	if (!head)
		return 0;

	Node* temp = head;
	int len = 0;

	do
	{
		len++;
		temp = temp->next;
	} while (temp != head);

	return len;
}

bool DoublyLinkedList::Empty()
{
	if (Length() > 0)
		return false;

	return true;
}

bool DoublyLinkedList::IsSorted()
{
	// Check if list is empty
	if (!head)
		return false;

	Node* p = head;
	do
	{
		if (p->data > p->next->data)
			return false;

		p = p->next;

	} while (p != head && p->next != head);

	return true;
}

void DoublyLinkedList::Sort()
{
	if (!head)
		return;

	int swapped = 0;
	Node* leading;
	Node* trailing;

	if (!head)
		return;

	do
	{
		swapped = 0;
		leading = head;
		trailing = leading->prev;
		while (leading != trailing)
		{
			if (leading->data > leading->next->data)
			{
				int temp = leading->data;
				leading->data = leading->next->data;
				leading->next->data = temp;
				swapped = 1;
			}

			leading = leading->next;
		}

		trailing = leading;
	} while (swapped);
}

void DoublyLinkedList::SortedInsert(int value)
{
	InsertFront(value);
	Sort();
}

void DoublyLinkedList::RemoveDuplicates()
{
	Node* leading = head;
	Node* next;
	do
	{
		if (leading->data != leading->next->data)
			leading = leading->next;
		else
		{
			leading->prev->next = leading->next;
			leading->next->prev = leading->prev;
			next = leading->next;
			delete leading;
			leading = next;
		}
	} while (leading != head);
}
