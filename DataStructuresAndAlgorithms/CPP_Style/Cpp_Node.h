#pragma once
#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;

	// Swap the nodes
	void Swap1(int a, int b);
	Node* Swap(Node* a, Node* b);
	void RReverseLinks(Node* head, Node** headPtr);
public:
	LinkedList() { head = nullptr; }
	LinkedList(int A[], int n);
	~LinkedList();
	void SetHead(Node* head) { this->head = head; }
	Node** GetHead() { return &head; }
	void Display();
	int Insert(int index, int x);
	int Delete(int index);
	int Length();
	void Sort();
	bool IsSorted();
	void RemoveDuplicates();
	void ReverseData();
	void ReverseLinks();

	// Wrapper for the Recursive Reverse Links!
	void Reverse();

	Node* Concat(Node** second);
	Node* Merge(LinkedList& second);

	bool IsLooped();
};