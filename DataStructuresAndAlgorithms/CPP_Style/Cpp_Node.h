#pragma once
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

	void Swap(Node* a, Node* b)
	{
		Node* temp = a;
		a = b;
		b = temp;
	}

public:
	LinkedList() { head = nullptr; }
	LinkedList(int A[], int n);
	~LinkedList();

	void Display();
	int Insert(int index, int x);
	int Delete(int index);
	int Length();
	void Sort();
};