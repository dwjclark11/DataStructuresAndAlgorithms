#pragma once

class DoublyLinkedList 
{
private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};

	Node* head;

public:
	DoublyLinkedList();
	DoublyLinkedList(int* A, int n);
	~DoublyLinkedList();

	void Display();
	void InsertFront(int value);
	void Insert(int value, int index);
	void InsertBack(int value);
	int Length();
	bool Empty();
	bool IsSorted();
	void Sort();
	void SortedInsert(int value);
	void RemoveDuplicates();
};