#include "C_Style/C_Node.h"

int main()
{
	int A[] = { 43, 18, 7, 21, 15 };
	struct C_LinkedList cll; 
	struct Node* head = NULL;
	struct Node* tempNode = NULL;

	cll.Create(A, sizeof(A) / sizeof(A[0]), head);
	
	cll.Insert(head, 0, 44);
	cll.Insert(head, 0, 18);
	
	if (head)
		printf("NOT NUL\n");
	else
		printf("NULL\n");

	cll.Display(head);
	printf("Deleted %d", cll.Delete(head, 2));
	cll.reverse(&head);
	printf("Reversed Links\n");
	cll.Display(head);
	return 0;
}