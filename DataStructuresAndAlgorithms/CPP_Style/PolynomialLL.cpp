#include "PolynomialLL.h"
#include <iostream>

PolynomialLL::Node* PolynomialLL::Swap(Node* a, Node* b)
{
	Node* temp = b->next;
	b->next = a;
	a->next = temp;

	return b;
}

void PolynomialLL::Sort()
{
	Node** headPtr;
	int swap = 0;
	
	for (int i = 0; i < terms; i++)
	{
		headPtr = &first;
		swap = 0;

		for (int j = 0; j < terms - i; j++)
		{
			Node* p1 = *headPtr;
			Node* p2 = p1->next;

			if (!p2) break;

			if (p1->exp < p2->exp)
			{
				*headPtr = Swap(p1, p2);
				swap = 1;
			}

			headPtr = &(*headPtr)->next;
		}

		if (!swap) break;
	}

}

void PolynomialLL::Delete()
{
	if (first)
	{
		Node* p = first;
		Node* next = nullptr;
		while (p)
		{
			next = p->next;
			delete p;
			p = next;
		}
		first = nullptr;
	}
}

PolynomialLL::PolynomialLL()
	: first(nullptr)
{

	std::cout << "Enter num terms: \n";
	std::cin >> terms;
	std::cout << "Enter each term with coeff and exp: \n";

	Node* t, * last = nullptr;

	for (int i = 0; i < terms; i++)
	{
		t = new Node;
		std::cout << "Term[" << i + 1 << "]: \n";
		std::cout << "Enter Coeff: \n";
		std::cin >> t->coeff;
		std::cout << "Enter Exp: \n";
		std::cin >> t->exp;
		t->next = nullptr;

		if (!first)
		{
			first = last = t;
		}
		else
		{
			last->next = t;
			last = t;
		}
	}
}

PolynomialLL::~PolynomialLL()
{
	Delete();
}

void PolynomialLL::Display()
{
	Node* p = first;

	while (p)
	{
		if (p->exp > 1)
			std::cout << p->coeff << "x^" << p->exp;
		else if (p->exp == 1)
			std::cout << p->coeff << "x";
		else if (p->exp == 0)
			std::cout << p->coeff;

		if (p->next)
			std::cout << " + ";

		p = p->next;
	}
	std::cout << std::endl;
}

double PolynomialLL::Evaluate(int x)
{
	double sum = 0.0;
	Node* p = first;

	while (p)
	{
		sum += p->coeff * pow(x, p->exp);
		p = p->next;
	}

	return sum;
}

void PolynomialLL::Add(PolynomialLL& rhs)
{
	Node* p = first;
	Node* r = *rhs.GetFirstTerm();
	*rhs.GetFirstTerm() = nullptr;

	while (p->next)
		p = p->next;

	p->next = r;

	terms += rhs.GetTerms();
	Sort();
	
	p = first;
	
	r = first->next;

	while (r)
	{
		if (p->exp == r->exp)
		{
			Node* t = r;
			p->coeff += r->coeff;
			r = r->next;
			p->next = r;
			delete t;
		}
		else
		{
			p = p->next;
			r = r->next;
		}
	}
	
	p->next = nullptr;
	
}

void PolynomialLL::operator+(PolynomialLL& rhs)
{
	Add(rhs);
}
