#include "SparseMatrixLL.h"
#include <iostream>
SparseMatrixLL::SparseMatrixLL()
	: first(nullptr)
{
	std::cout << "Enter num rows: \n";
	std::cin >> rows;
	std::cout << "Enter num cols: \n";
	std::cin >> cols;
	
	Node* p = nullptr;
	bool firstLink = false;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			int data = 0;
			std::cout << "Enter data [" << i << "][" << j << "]: \n";

			std::cin >> data;

			if (data <= 0)
				continue;

			if (!first &&  data > 0)
			{
				first = new Node;
				first->val = data;
				first->col = j;
				first->row = i;
				first->next = nullptr;
				p = first;
				continue;
			}

			if (data > 0)
			{
				while (p->next)
					p = p->next;

				Node* t = new Node;
				t->val = data;
				t->col = j;
				t->row = i;
				t->next = nullptr;

				p->next = t;

				if (!firstLink)
				{
					first->next = t;
					firstLink = true;
				}
			}
			p = first;
		}
}

SparseMatrixLL::~SparseMatrixLL()
{
	Node* p = first;
	while (p)
	{
		Node* t = p;
		p = p->next;
		delete t;
	}	
}

void SparseMatrixLL::Display()
{
	Node* p = first;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (p)
			{
				if (j == p->col && i == p->row)
				{
					std::cout << p->val << " ";
					p = p->next;
				}
				else
				{
					std::cout << "0 ";
				}
			}
			else
				std::cout << "0 ";
		}
		std::cout << "\n";
	}
}

void SparseMatrixLL::Append(int row, int col, int val)
{
	// If matrix is empty, there is nothing to append
	if (!first)
		return;

	if (rows < row - 1 || cols < col - 1)
	{
		std::cout << "ERROR: Not a valid row or col index" << std::endl;
		return;
	}
		
	Node* p = first;

	if (row - 1 <= 0)
		row = 1;

	if (col - 1 <= 0)
		col = 1;

	while (p)
	{
		if (p->row == row - 1 && p->col == col - 1)
		{
			p->val = val;
			break;
		}
		else
			p = p->next;
	}
}
