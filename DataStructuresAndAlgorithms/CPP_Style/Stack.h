#pragma once
#include <iostream>

template <typename T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

private:
	Node* top;

public:
	Stack();
	~Stack();

	void push(T x);
	T pop();
	void Display();
};

template<typename T>
inline Stack<T>::Stack()
{
	top = nullptr;
}

template<typename T>
inline Stack<T>::~Stack()
{
}

template<typename T>
inline void Stack<T>::push(T x)
{
	Node* t = new Node;
	if (!t)
		std::cout << "Stack is full!\n";
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

template<typename T>
inline T Stack<T>::pop()
{
	if (!top)
		std::cout << "Stack is empty!\n";
	else
	{
		T x = top->data;
		Node* t = top;
		top = top->next;
		delete t;
		return x;
	}

	return T();
}

template<typename T>
inline void Stack<T>::Display()
{
	Node* p = top;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}

	std::cout << std::endl;
}
