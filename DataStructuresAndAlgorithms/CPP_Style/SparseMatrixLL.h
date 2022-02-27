#pragma once

class SparseMatrixLL
{
private:
	struct Node
	{
		int col;
		int row;
		int val;
		Node* next;
	};

	Node* first;
	int rows;
	int cols;
public:
	SparseMatrixLL();
	~SparseMatrixLL();

	void Display();
	void Append(int row, int col, int val);
};