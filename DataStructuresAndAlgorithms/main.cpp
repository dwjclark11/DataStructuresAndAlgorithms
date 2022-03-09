
#include "CPP_Style/AVL.h"
#include <iostream>
int main()
{
	AVL<float> avl;
	avl.Insert(5);
	avl.Insert(25);
	avl.Insert(15);
	avl.Insert(6);
	avl.Insert(1);

	avl.InOrder();
	avl.Delete(15);
	//avl.Delete(25);
	//avl.Delete(1);
	std::cout << std::endl;
	avl.InOrder();

	return 0;
} 