#include "C_Style/C_Node.h"

int main()
{
	int A[] = { 3, 5, 7, 10, 15 };
	struct C_LinkedList cll; 
	cll.Create(A, sizeof(A) / sizeof(A[0]));

	cll.RDisplay(first, true);
	printf("Sum: %d", cll.RSumOfNodes(first));
	return 0;
}