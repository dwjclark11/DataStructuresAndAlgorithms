#include "C_Style/C_Node.h"

int main()
{
	int A[] = { 43, 18, 7, 21, 15 };
	struct C_LinkedList cll; 
	////struct Node* tempNode = NULL;
	//cll.Create(A, sizeof(A) / sizeof(A[0]));


	//cll.Display(first);
	//cll.Sort(first);
	//printf("Sorted\n");
	//cll.Display(first);
	cll.SortedInsert(first, 33);
	cll.SortedInsert(first, 25);
	printf("After SortedInsert\n");
	cll.Display(first);
	return 0;
}