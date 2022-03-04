
#include "C_Style/C_Binary_Tree.h"

int main()
{
	struct TNode* root = NULL;
	
	CreateTree(&root);
	printf("Pre Order: ");
	PreOrder_Display(root);
	printf("\nPost Order: ");
	PostOrder_Display(root);
	printf("\nIn Order: ");
	InOrder_Display(root);

	return 0;
} 