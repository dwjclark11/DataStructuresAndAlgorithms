
#include "C_Style/AVL.h"

int main()
{
    RInsert(&root, 50);
    RInsert(&root, 10);
    RInsert(&root, 20);
    RInsert(&root, 25);
    RInsert(&root, 15);
    Delete(&root, 15);


	return 0;
} 