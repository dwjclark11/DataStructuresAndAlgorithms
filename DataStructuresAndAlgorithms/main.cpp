
#include "C_Style/BST.h"

int main()
{
	Node* root = NULL;
	Node* temp = NULL;

	RInsert(&root, 50);
	RInsert(&root, 10);
	RInsert(&root, 40);
	RInsert(&root, 20);
	RInsert(&root, 30);

	Delete(&root, 50);

	InOrder(root);

	temp = search(root, 4);

	if (temp)
		printf("element %d is found\n", temp->data);
	else
		printf("element is not found\n");

	return 0;
} 