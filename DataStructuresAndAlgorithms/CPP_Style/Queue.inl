#include "Queue.h"

template<typename T>
Queue<T>::Queue()
	: front(nullptr)
	, rear(nullptr)
{

}

template<typename T>
Queue<T>::~Queue()
{

}

template<typename T>
void Queue<T>::push_back(T x)
{
	Node* t = new Node;
	t->data = x;
	t->next = nullptr;

	if (!front)
		front = rear = t;
	else
	{
		rear->next = t;
		rear = t;
	}
}

template<typename T>
T Queue<T>::pop_front()
{
	T data = T();
	if (!front)
		std::cout << "queue is empty\n";
	else
	{
		Node* p = front;
		data = p->data;
		front = front->next;
		delete p;
	}
	return data;
}

template<typename T>
int Queue<T>::size()
{
	int len = 0;
	Node* p = front;
	while (p)
	{
		len++;
		p = p->next;
	}

	return len;
}

template<typename T>
T Queue<T>::get_front()
{
	return front ? front->data : T();
}

template<typename T>
T Queue<T>::get_back()
{
	return rear ? rear->data : T();
}

template<typename T>
void Queue<T>::Display()
{
	Node* p = front;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}

	std::cout << std::endl;
}
