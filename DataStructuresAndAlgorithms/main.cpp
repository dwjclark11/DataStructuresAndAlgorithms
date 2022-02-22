#include <stdlib.h>
#include <crtdbg.h>



//#include "CPP_Style/Cpp_Node.h"
//#include "C_Style/C_Node.h"
#include "C_Style/DoublyLinkedList.h"

int main()
{
	int A[] = { 2, 3, 4, 4, 6 };
	DoublyLinkedList list;
	Node* head = NULL;
	
	list.Create(A, sizeof(A) / sizeof(A[0]), head);

	list.Display(head);
	list.Insert(10, 1, head);
	list.Display(head);
	list.Insert(15, 0, head);
	list.Display(head);
	list.Delete(0, head);
	list.Display(head);

	printf("Length: %d", list.Length(head));

	return 0;
}