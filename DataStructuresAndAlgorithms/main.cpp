#include "C_Style/C_Node.h"

int main()
{
	int A[] = { 3, 5, 7, 21, 15 };
	struct C_LinkedList cll; 
	struct Node* tempNode = NULL;
	cll.Create(A, sizeof(A) / sizeof(A[0]));

	cll.Display(first);
	printf("Min: %d\n", cll.RMin(first));
	printf("Max: %d\n", cll.Max(first));
	printf("Sum: %d\n", cll.SumOfNodes(first));

	tempNode = cll.Search(first, 21);
	tempNode = cll.Search(first, 15);

	if (tempNode)
		printf("Key is Found %d at %d\n", tempNode->data, &tempNode);
	else
		printf("Key Not Found!\n");

	cll.Display(first);

	return 0;
}