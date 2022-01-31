
#include "CPP_Style/Cpp_Node.h"

int main()
{
	int A[] = { 43, 18, 7, 21, 15 };
	int B[] = { 9, 14, 21, 1, 85 };


	LinkedList list(A, sizeof(A) / sizeof(A[0]));
	list.Display();
	list.Delete(2);
	list.Display();
	return 0;
}