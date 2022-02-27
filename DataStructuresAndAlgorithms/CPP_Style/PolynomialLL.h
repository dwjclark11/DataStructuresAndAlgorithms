#pragma once
class PolynomialLL
{
private:
	struct Node
	{
		int coeff;
		int exp;
		Node* next;
	};

private:
	Node* first;
	int terms;

private:
	Node* Swap(Node* a, Node* b);
	void Sort();
	void Delete();

public:
	PolynomialLL();
	~PolynomialLL();

	// Display a formatted Polynomial
	void Display();
	// Evaluate for x
	double Evaluate(int x);
	// Add two polynomial linked lists
	void Add(PolynomialLL& rhs);
	// This is not needed --> Just alls the add Function
	void operator+(PolynomialLL& rhs);

	Node** GetFirstTerm() { return &first; }
	int GetTerms() { return terms; }
};
