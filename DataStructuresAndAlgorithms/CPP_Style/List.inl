#include "List.h"
#include <iostream>

// Private sort function used for sorted insert and other functions
template<typename T>
inline void List<T>::sort()
{
	if (!head)
		return;

	int swapped = 0;
	Node* leading;
	Node* trailing;

	do
	{
		swapped = 0;
		leading = head;
		trailing = leading->prev;
		
		while (leading != trailing)
		{
			if (leading->data > leading->next->data)
			{
				T temp = leading->data;
				leading->data = leading->next->data;
				leading->next->data = temp;
				swapped = 1;
			}

			leading = leading->next;
		}
		trailing = leading;
	} while (swapped);
}

template<typename T>
inline List<T>::List()
	: head(nullptr)
{

}

template<typename T>
inline List<T>::List(T* A, int n)
	: head(nullptr)
{
	Node* last = nullptr, * t;
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

template<typename T>
inline List<T>::~List()
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

template<typename T>
inline void List<T>::Display()
{
	// If empty there is nothing to display
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

template<typename T>
inline void List<T>::push_front(T value)
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

template<typename T>
inline void List<T>::push_index(T value, int index)
{
	// Get the length
	int len = length();

	// if the index is outside of the allowed range, exit the function
	if (index < 0 || index > len)
		return;

	if (index == 0)
		push_front(value);
	else if (index == len)
		push_back(value);
	else
	{
		Node* t = new Node;
		Node* p = head;
		t->data = value;

		// Move pointer 'p' to the index previous to desired index
		for (int i = 0; i < index - 1; i++)
			p = p->next;

		t->next = p->next;
		t->prev = p;
		p->next->prev = t;
		p->next = t;

	}
}

template<typename T>
inline void List<T>::push_back(T value)
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

template<typename T>
inline T List<T>::pop_front()
{
	T data = T();
	if (!head)
		return data;
	
	// Create a temp variable so we can delete the head node
	Node* temp = head;
	// Take the data for the return
	data = temp->data;
	// Set the head node to the next node
	head = head->next;
	
	head->prev = temp->prev;
	temp->prev->next = head;

	// Delete the data at this node
	delete temp;

	// return the data that was at the head node
	return data;
}

template<typename T>
inline T List<T>::pop_back()
{
	T data = T();
	if (!head)
		return data;
	
	if (length() > 1)
	{
		Node* p = head->prev;
		data = p->data;

		head->prev->prev->next = head;
		head->prev = head->prev->prev;

		delete p;
	}
	else
	{
		data = head->data;
		delete head;

		head = nullptr;
	}

	return data;
}

template<typename T>
inline int List<T>::length()
{
	// If the head node is nullptr == length must be zero
	if (!head)
		return 0;

	Node* p = head;
	int len = 0;
	do
	{
		len++;
		p = p->next;
	} while (p != head);


	return len;
}

template<typename T>
inline bool List<T>::empty()
{
	if (length() > 0)
		return false;

	// if the length is 0 or less it is empty
	return true;
}

template<typename T>
inline bool List<T>::isSorted()
{
	// If the list is empty in can't be sorted
	if (!head)
		return false;
	
	// Create a temporary pointer to the head node
	Node* p = head;

	do
	{
		// This is based on an ascending ordering
		if (p->data > p->next->data)
			return false;
		// Move p to the next node
		p = p->next;

	} while (p != head && p->next != head);

	return true;
}

template<typename T>
inline void List<T>::sorted_insert(T value)
{
	// Push the value to the front of the list
	push_front(value);
	// Sort the list
	sort();
}

template<typename T>
inline void List<T>::remove_duplicates()
{
	Node* leading = head;
	Node* next;

	do
	{
		// If leading and the next node are not the same, set leading to the next node
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
