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

public:
	LinkedList() { head = nullptr; }
	LinkedList(int A[], int n);
	~LinkedList();

	void Display();
	int Insert(int index, int x);
	int Delete(int index);
	int Length();
	void Sort();
	bool IsSorted();
	void RemoveDuplicates();
	void ReverseData();
	void ReverseLinks();
};