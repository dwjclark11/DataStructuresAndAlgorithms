#pragma once
#include <iostream>
template <typename T>
class Node
{
public:
	T data;
	Node* next;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* head;

	// Swap the nodes
	void Swap1(T a, T b);
	Node<T>* Swap(Node<T>* a, Node<T>* b);
	void RReverseLinks(Node<T>* head, Node<T>** headPtr);
public:
	LinkedList() { head = nullptr; }
	LinkedList(T A[], int n);
	~LinkedList();
	void SetHead(Node<T>* head) { this->head = head; }
	Node<T>** GetHead() { return &head; }
	void Display();
	T Insert(int index, T x);
	T Delete(int index);
	int Length();
	void Sort();
	bool IsSorted();
	void RemoveDuplicates();
	void ReverseData();
	void ReverseLinks();

	// Wrapper for the Recursive Reverse Links!
	void Reverse();

	Node<T>* Concat(Node<T>** second);
	Node<T>* Merge(LinkedList<T>& second);

	bool IsLooped();
};

#include "New_Cpp_Node.inl"