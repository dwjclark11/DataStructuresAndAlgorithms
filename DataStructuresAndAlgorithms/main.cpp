

#include <iostream>
#include "Sorting_Techniques/Sort.h"

int main()
{
	int A[]{ 15, 8, 1, 2, 5,7,4 };

	std::cout << "Not Sorted: ";

	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
		std::cout <<  A[i] << " ";

	std::cout << std::endl;

	bubbleSort<int>(A, sizeof(A) / sizeof(A[0]));

	std::cout << "Sorted: ";
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
		std::cout << A[i] << " ";

	std::cout << std::endl;


	return 0;
} 