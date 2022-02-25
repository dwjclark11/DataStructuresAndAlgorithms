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
	
	list.Create(A, sizeof(A) / sizeof(A[0]), head, true);

	////list.Reverse(head);
	//list.Display(head);
	////list.Sort(head);
	////list.Display(head);
	list.Insert(15, 0, head);
	list.Insert(13, 0, head);
	list.Insert(14, 0, head);
	list.Insert(110, 0, head);
	list.Insert(150, 0, head);
	//list.Insert(8, 0, head);
	//list.Insert(13, 0, head);
	//list.Insert(7, 0, head);
	//list.Insert(12, 0, head);
	list.Insert(66, 0, head);
	list.SortedInsert(head, 45);
	list.Insert(3000, 4, head);
	if (list.IsSorted(head) == 1)
		printf("sorted\n");
	else
		printf("not sorted\n");

	//list.Display(head);
	//list.Delete(5, head);
	list.Display(head);
	list.Reverse(head);
	list.Display(head);
	//list.Sort(head);
	//list.Display(head);
	//list.SortedInsert(head, 4);
	//list.Display(head);
	//list.RemoveDuplicates(head);
	//list.Display(head);
	//list.SortedInsert(head, 7);
	//list.SortedInsert(head, 9);
	//list.SortedInsert(head, 13);
	//list.SortedInsert(head, 14);

	//list.Display(head);
	//printf("Middle: %d\n", list.FindMiddleNumber(head));


	//if (list.IsSorted(head))
	//	printf("Length: %d", list.Length(head));
	//else
	//	printf("Not Sorted!");
	return 0;
}