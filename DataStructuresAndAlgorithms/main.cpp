#include "C_Style/C_Node.h"

int main()
{
	int A[] = { 43, 18, 7, 21, 15 };
	struct C_LinkedList cll; 
	////struct Node* tempNode = NULL;
	cll.Create(A, sizeof(A) / sizeof(A[0]));


	//cll.Display(first);
	//cll.Sort(first);
	//printf("Sorted\n");
	//cll.Display(first);
	cll.SortedInsert(first, 33);
	cll.SortedInsert(first, 33);
	cll.SortedInsert(first, 25);
	cll.SortedInsert(first, 25);
	//cll.Insert(first, 5, 99);
	printf("After SortedInsert\n");
	cll.Display(first);
	//cll.Delete(first, 5);
	printf("After Delete\n");
	cll.Display(first);
	if (cll.IsSorted(first))
		printf("Sorted");
	else
		printf("not Sorted!\n");
	cll.RemoveDuplicates(first);
	printf("Duplicates removed!\n");
	cll.Display(first);
	cll.ReverseData(first);
	printf("Reversed Data!\n");
	cll.Display(first);
	cll.ReverseLinks(first);
	printf("Reversed Links!\n");
	cll.Display(first);
	cll.RReverseLinks(NULL, first);
	printf("Recursive Reversed Links!\n");
	cll.Display(first);
	return 0;
}