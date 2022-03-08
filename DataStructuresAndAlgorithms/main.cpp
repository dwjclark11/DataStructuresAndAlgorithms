
#include "CPP_Style/BST.h"

int main()
{
	BST<int> bst;

	bst.rInsert(7);
	bst.rInsert(5);
	bst.rInsert(10);
	bst.rInsert(21);
	bst.rInsert(16);
	bst.rInsert(50);
	bst.InOrder();
	std::cout << std::endl;

	if (bst.Search(10))
		std::cout << "Node exists!\n";
	else
		std::cout << "Node does not exist\n";
	
	bst.Delete(10);
	bst.InOrder();

	if (bst.Search(10))
		std::cout << "Node exists!\n";
	else
		std::cout << "Node does not exist\n";

	return 0;
} 