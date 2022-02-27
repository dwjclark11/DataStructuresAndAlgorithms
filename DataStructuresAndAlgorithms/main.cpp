#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>


#include "CPP_Style/DoublyLinkedList.h"
#include "CPP_Style/SparseMatrixLL.h"


int main()
{
	SparseMatrixLL sm;
	sm.Display();
	sm.Append(3, 2, 6);
	std::cout << std::endl;
	sm.Display();
	return 0;
}