
#include "CPP_Style/Cpp_Node.h"

int main()
{
	int A[] = { 43, 18, 7, 7, 7, 21, 15, 15 };
	int B[] = { 9, 14, 21, 1, 85 };


	LinkedList list(A, sizeof(A) / sizeof(A[0]));
	list.Display();
	
	if (list.IsSorted())
		std::cout << "Sorted" << std::endl;
	else
		std::cout << "Not Sorted" << std::endl;
	std::cout << "in\n";
	list.Sort();
	
	list.Display();
	
	if (list.IsSorted())
		std::cout << "Sorted" << std::endl;
	else
		std::cout << "Not Sorted" << std::endl;
	list.RemoveDuplicates();
	list.Display();
	list.ReverseLinks();
	list.Display();
	return 0;
}