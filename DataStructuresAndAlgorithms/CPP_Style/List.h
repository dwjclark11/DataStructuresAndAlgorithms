#pragma once

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};

private:
	Node* head;

private:
	void sort();

public:
	List();
	List(T* A, int n);
	~List();

	void Display();
	void push_front(T value);
	void push_index(T value, int index);
	void push_back(T value);
	T pop_front();
	T pop_back();

	int length();
	bool empty();
	bool isSorted();

	void sorted_insert(T value);
	void remove_duplicates();

};

#include "List.inl"

