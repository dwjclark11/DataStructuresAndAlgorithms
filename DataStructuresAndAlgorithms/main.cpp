#include <stdlib.h>
#include <crtdbg.h>



//#include "CPP_Style/Cpp_Node.h"
#include "C_Style/C_Node.h"


int main()
{
	int A[] = { 2, 3, 4, 4, 6 };
	Circ_LinkedList list;
	Node* head = NULL;
	list.Create(A, sizeof(A) / sizeof(A[0]), head);
	
	list.Display(head);
	list.Insert(0, 24, head);
	list.Display(head);
	list.Delete(&head, 2);
	list.Display(head);
	return 0;
}