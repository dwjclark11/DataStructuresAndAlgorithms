#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>


#include "CPP_Style/DoublyLinkedList.h"
#include "CPP_Style/SparseMatrixLL.h"
#include "CPP_Style/PolynomialLL.h"


int main()
{
	PolynomialLL poly;
	PolynomialLL poly2;

	poly.Display();
	
	poly + poly2;

	poly.Display();
	//std::cout << "Eval: " << poly.Evaluate(3) << std::endl;

	return 0;
}