#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>


#include "CPP_Style/DoublyLinkedList.h"

//#include "C_Style/C_Node.h"
//#include "C_Style/DoublyLinkedList.h"

int main()
{
	//int A[] = { 4, 5, 40, 15, 11 };
	//DoublyLinkedList list(A, sizeof(A) / sizeof(A[0]));
	DoublyLinkedList list;

	std::cout << list.Length() << std::endl;
	list.Display();
	list.InsertBack(7);
	std::cout << list.Length() << std::endl;
	list.Display();
	list.InsertBack(1);
	std::cout << list.Length() << std::endl;
	
	list.Display();
	list.InsertBack(5);
	std::cout << list.Length() << std::endl;
	list.Display();
	list.Sort();
	list.Display();
	list.Insert(42, 2);
	list.Insert(42, 2);
	list.Insert(42, 2);
	if (list.IsSorted())
		std::cout << "Sorted\n";
	else
		std::cout << "Not Sorted\n";
	list.Display();
	list.RemoveDuplicates();
	list.Display();

	return 0;
}