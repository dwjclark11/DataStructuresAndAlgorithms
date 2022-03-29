#pragma once
#include <iostream>

template <typename T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

private:
	Node* front;
	Node* rear;

public:
	Queue();
	~Queue();

	void push_back(T);
	T pop_front();
	int size();
	T get_front();
	T get_back();
	void Display();
	inline bool isEmpty() { return front == nullptr; }
};

#include "Queue.inl"

